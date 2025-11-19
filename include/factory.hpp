// include/factory.hpp

#pragma once

#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>

class Factory {
 public:
  Factory(const sf::RenderWindow &window, entt::registry &registry);

  void SpawnPlayer();

 private:
  const sf::RenderWindow &window_;
  entt::registry &registry_;
};