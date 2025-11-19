// src/systems/player_control_system.cpp

#include "systems/player_control_system.hpp"

#include <cmath>

#include "components/physics.hpp"
#include "components/player.hpp"

void PlayerControlSystem(entt::registry& registry) {
  auto& player_input = registry.ctx().get<PlayerInput>();

  float direction_x{};
  float direction_y{};

  if (player_input.up) {
    direction_y += -1;
  }
  if (player_input.down) {
    direction_y += 1;
  }
  if (player_input.left) {
    direction_x += -1;
  }
  if (player_input.right) {
    direction_x += 1;
  }

  const auto magnitude = hypot(direction_x, direction_y);

  if (magnitude != 0) {
    direction_x /= magnitude;
    direction_y /= magnitude;
  }

  for (auto [entity, velocity] : registry.view<PlayerTag, Velocity>().each()) {
    velocity.dx = direction_x * 400;
    velocity.dy = direction_y * 400;
  }
}