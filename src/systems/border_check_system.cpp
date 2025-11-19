// src/systems/border_check_system.cpp

#include "systems/border_check_system.hpp"

#include <SFML/Graphics.hpp>

#include "components/geometry.hpp"
#include "components/physics.hpp"

void BorderCheckSystem(entt::registry& registry) {
  auto& window = registry.ctx().get<sf::RenderWindow&>();
  auto& dispatcher = registry.ctx().get<entt::dispatcher&>();

  for (auto [entity, position, velocity] : registry.view<Position, Velocity>().each()) {
    float half_width{};
    float half_height{};

    if (const auto* radius = registry.try_get<const Radius>(entity)) {
      half_width = radius->r;
      half_height = radius->r;
    } else if (const auto* size = registry.try_get<const Size>(entity)) {
      half_width = size->x / 2.0f;
      half_height = size->y / 2.0f;
    }

    if (position.x - half_width < 0) {
      position.x = half_width;
    } else if (position.x + half_width > window.getSize().x) {
      position.x = window.getSize().x - half_width;
    }

    if (position.y - half_height < 0) {
      position.y = half_height;
    } else if (position.y + half_height > window.getSize().y) {
      position.y = window.getSize().y - half_height;
    }
  }
}