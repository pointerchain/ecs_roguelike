// include/game.hpp

#pragma once

#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>

#include "config.hpp"
#include "factory.hpp"

class Game {
 public:
  Game();

  void Run();

 private:
  sf::RenderWindow window_{
      sf::VideoMode(sf::Vector2u(Config::Window::kWidth, Config::Window::kHeight)),
      Config::Window::kName, sf::Style::Titlebar | sf::Style::Close};
  entt::registry registry_{};
  entt::dispatcher dispatcher_{};
  sf::Clock clock_{};
  Factory factory_{window_, registry_};
};