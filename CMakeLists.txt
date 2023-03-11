cmake_minimum_required(VERSION 3.24)
project(KillerKitty)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(engine)

file(GLOB SRC src/*)

if(APPLE)
    add_executable(KillerKitty MACOSX_BUNDLE ${SRC})
    target_link_libraries(KillerKitty KillerKittyEngine)
    set_target_properties(KillerKitty PROPERTIES
            BUNDLE True
            MACOSX_BUNDLE_GUI_IDENTIFIER my.domain.style.identifier.KillerKitty
            MACOSX_BUNDLE_BUNDLE_NAME KillerKitty
            MACOSX_BUNDLE_BUNDLE_VERSION "0.1"
            MACOSX_BUNDLE_SHORT_VERSION_STRING "0.1"
            )
else()
    add_executable(KillerKitty ${SRC})
    target_link_libraries(KillerKitty KillerKittyEngine)
endif()
