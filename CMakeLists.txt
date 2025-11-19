cmake_minimum_required(VERSION 3.10)

project(ProjectName)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find_package(SFML COMPONENTS System Window Graphics CONFIG REQUIRED)
# find_package(EnTT CONFIG REQUIRED)

add_executable(${PROJECT_NAME}
    src/main.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE include)

# target_link_libraries(${PROJECT_NAME} PRIVATE
#   SFML::System
#   SFML::Window
#   SFML::Graphics
#   EnTT::EnTT
# )