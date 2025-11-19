// src/systems/cleanup_system.cpp

#include "systems/cleanup_system.hpp"

#include "components/to_destroy.hpp"

void CleanupSystem(entt::registry& registry) {
  auto& dispatcher = registry.ctx().get<entt::dispatcher&>();

  const auto view = registry.view<ToDestroy>();
  registry.destroy(view.begin(), view.end());

  dispatcher.clear();
}