cmake_minimum_required(VERSION 3.10)

project(ecs_roguelike)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML COMPONENTS System Window Graphics CONFIG REQUIRED)
find_package(EnTT CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(ryml CONFIG REQUIRED)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/game.cpp
    src/factory.cpp

    src/systems/event_system.cpp
    src/systems/player_control_system.cpp
    src/systems/physics_system.cpp
    src/systems/border_check_system.cpp
    src/systems/render_system.cpp
    src/systems/cleanup_system.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE include)

target_link_libraries(${PROJECT_NAME} PRIVATE
  SFML::System
  SFML::Window
  SFML::Graphics
  EnTT::EnTT
  nlohmann_json::nlohmann_json
  ryml::ryml
)