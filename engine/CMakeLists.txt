cmake_minimum_required(VERSION 3.24)
project(KillerKittyEngine)

set(CMAKE_CXX_STANDARD 20)

set(SFML_STATIC_LIBRARIES TRUE)
add_subdirectory(deps/SFML)
add_subdirectory(deps/json)
add_subdirectory(deps/box2d)

file(GLOB SRC src/* src/Entities/* src/UI/*)
file(GLOB INCLUDE include/* include/Entities/* include/UI/*)
add_library(KillerKittyEngine ${SRC} ${INCLUDE})
target_include_directories(KillerKittyEngine PUBLIC ${SFML_INCLUDE_DIR} include)
target_link_libraries(KillerKittyEngine sfml-graphics sfml-audio sfml-system sfml-window nlohmann_json box2d)
