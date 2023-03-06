cmake_minimum_required(VERSION 3.24)
project(KillerKitty)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(engine)

file(GLOB SRC src/*)
add_executable(KillerKitty ${SRC})
target_link_libraries(KillerKitty KillerKittyEngine)
