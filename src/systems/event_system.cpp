// src/systems/event_system.cpp

#include "systems/event_system.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "components/player.hpp"

// #include "events/input_event.hpp"

void EventSystem(entt::registry& registry) {
  auto& window = registry.ctx().get<sf::RenderWindow>();
  auto& dispatcher = registry.ctx().get<entt::dispatcher>();
  auto& player_input = registry.ctx().get<PlayerInput>();

  const auto update_input = [&](const sf::Keyboard::Scancode scancode, const bool is_pressed) {
    switch (scancode) {
      case sf::Keyboard::Scancode::W:
        player_input.up = is_pressed;
        break;
      case sf::Keyboard::Scancode::S:
        player_input.down = is_pressed;
        break;
      case sf::Keyboard::Scancode::A:
        player_input.left = is_pressed;
        break;
      case sf::Keyboard::Scancode::D:
        player_input.right = is_pressed;
        break;
      default:
        break;
    }
  };

  const auto onClose = [&](const sf::Event::Closed&) { window.close(); };
  const auto keyPress = [&](const sf::Event::KeyPressed& key_pressed) {
    update_input(key_pressed.scancode, true);
  };
  const auto keyRelease = [&](const sf::Event::KeyReleased& key_released) {
    update_input(key_released.scancode, false);
  };

  window.handleEvents(onClose, keyPress, keyRelease);
}