// include/config.hpp

#pragma once

#include <sys/types.h>
namespace Config {

namespace Window {

constexpr const char* kName{"ECS Roguelike"};
constexpr unsigned int kWidth{2160};
constexpr unsigned int kHeight{1200};

}  // namespace Window

namespace Player {

constexpr float kWidth{32.f};
constexpr float kHeight{32.f};

}  // namespace Player

namespace ScoreUi {

constexpr uint kCharacterSize{100};
constexpr const char* kFontPath{"assets/ARIAL.TTF"};
constexpr const char* kTextFormat{"{}    |    {}"};

}  // namespace ScoreUi

}  // namespace Config