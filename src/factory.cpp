// src/factory.cpp

#include "factory.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

#include "components/drawable.hpp"
#include "components/geometry.hpp"
#include "components/physics.hpp"
#include "components/player.hpp"
#include "config.hpp"

Factory::Factory(const sf::RenderWindow &window, entt::registry &registry)
    : window_(window), registry_(registry) {}

void Factory::SpawnPlayer() {
  const auto player_entity = registry_.create();
  registry_.emplace<PlayerTag>(player_entity);
  registry_.emplace<Drawable>(player_entity);
  registry_.emplace<Size>(player_entity, Config::Player::kWidth, Config::Player::kHeight);
  registry_.emplace<Position>(player_entity, window_.getSize().x / 2, window_.getSize().y / 2);
  registry_.emplace<Velocity>(player_entity, 0, 0);
}
