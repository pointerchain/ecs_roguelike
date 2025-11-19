// src/game.cpp

#include "game.hpp"

#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>
#include <stdexcept>

#include "components/player.hpp"
#include "config.hpp"
#include "factory.hpp"
#include "systems/border_check_system.hpp"
#include "systems/cleanup_system.hpp"
#include "systems/event_system.hpp"
#include "systems/physics_system.hpp"
#include "systems/player_control_system.hpp"
#include "systems/render_system.hpp"

Game::Game() {
  sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
  const int x = (desktop.size.x - window_.getSize().x) / 2;
  const int y = (desktop.size.y - window_.getSize().y) / 2;
  window_.setPosition({x, y});

  registry_.ctx().emplace<sf::RenderWindow&>(window_);
  registry_.ctx().emplace<entt::dispatcher&>(dispatcher_);
  registry_.ctx().emplace<Factory&>(factory_);

  PlayerInput player_input{};
  registry_.ctx().emplace<PlayerInput>();

  sf::Font font;
  if (!font.openFromFile(Config::ScoreUi::kFontPath)) {
    throw std::runtime_error("Failed to load font: " + std::string(Config::ScoreUi::kFontPath));
  }
  registry_.ctx().emplace<sf::Font>(font);
}

void Game::Run() {
  // PaddleMovementSystem paddle_movement_system(registry_, dispatcher_);

  factory_.SpawnPlayer();

  while (window_.isOpen()) {
    const auto dt = clock_.restart().asSeconds();

    EventSystem(registry_);

    PlayerControlSystem(registry_);
    PhysicsSystem(registry_, dt);
    BorderCheckSystem(registry_);

    dispatcher_.update();

    RenderSystem(registry_);
    CleanupSystem(registry_);
  }
}