cmake_minimum_required(VERSION 3.0.0)
project(myengine2D VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(myengine2D main.cpp glad.h glad.c)

add_library(
    SHADER
    ./myEngine/Shader.cpp
    ./myEngine/Shader.hpp
)

add_library(
    CAMERA
    ./myEngine/Camera.cpp
    ./myEngine/Camera.hpp
)

add_library(
    MYENGINE
    ./myEngine/MyEngine.cpp
    ./myEngine/MyEngine.hpp
)

add_library(
    SCENE
    ./myEngine/Scene.cpp
    ./myEngine/Scene.hpp
)

add_library(
    ENTITY
    ./myEngine/Entity.cpp
    ./myEngine/Entity.hpp
)

add_library(
    PLAYER
    ./Player.cpp
    ./Player.hpp
)

add_library(
    ENEMY
    ./Enemy.cpp
    ./Enemy.hpp
)

target_link_libraries(SHADER PRIVATE -lglfw -lGL)
target_link_libraries(MYENGINE SHADER CAMERA ENTITY SCENE -lglfw -lGL)
target_link_libraries(myengine2D PRIVATE MYENGINE PLAYER ENEMY -lglfw -lGL)





set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
