// src/systems/render_system.cpp

#include "systems/render_system.hpp"

#include <SFML/Graphics.hpp>

#include "components/drawable.hpp"
#include "components/geometry.hpp"
#include "components/physics.hpp"
#include "components/ui.hpp"

void RenderSystem(entt::registry& registry) {
  auto& window = registry.ctx().get<sf::RenderWindow&>();
  auto& font = registry.ctx().get<sf::Font>();

  window.clear();

  sf::CircleShape circle{};
  sf::RectangleShape rectangle{};
  sf::Text text(font);

  for (auto [entity, position] : registry.view<const Position, Drawable>().each()) {
    if (const auto* radius = registry.try_get<const Radius>(entity)) {
      circle.setRadius(radius->r);
      circle.setOrigin({radius->r, radius->r});
      circle.setPosition({position.x, position.y});
      window.draw(circle);
    } else if (const auto* size = registry.try_get<const Size>(entity)) {
      rectangle.setSize({size->x, size->y});
      rectangle.setOrigin({size->x / 2.0f, size->y / 2.0f});
      rectangle.setPosition({position.x, position.y});
      window.draw(rectangle);
    } else if (const auto* score_ui = registry.try_get<const ScoreUi>(entity)) {
      //text.setString(std::vformat(score_ui->text_format,
      //                            std::make_format_args(game_score.left, game_score.right)));
      text.setCharacterSize(score_ui->character_size);
      text.setOrigin(text.getLocalBounds().getCenter());
      text.setPosition({position.x, position.y});
      window.draw(text);
    }
  }

  window.display();
}