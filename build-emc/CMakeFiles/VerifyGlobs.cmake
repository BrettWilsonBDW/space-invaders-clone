# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.26
cmake_policy(SET CMP0009 NEW)

# PROJECT_SOURCES at CMakeLists.txt:94 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "C:/Users/brend/Desktop/webdeploy/space-invaders-clone/src/*.cpp")
set(OLD_GLOB
  "C:/Users/brend/Desktop/webdeploy/space-invaders-clone/src/AssetManager.cpp"
  "C:/Users/brend/Desktop/webdeploy/space-invaders-clone/src/Debug.cpp"
  "C:/Users/brend/Desktop/webdeploy/space-invaders-clone/src/GameLoop.cpp"
  "C:/Users/brend/Desktop/webdeploy/space-invaders-clone/src/GameUtils.cpp"
  "C:/Users/brend/Desktop/webdeploy/space-invaders-clone/src/Player.cpp"
  "C:/Users/brend/Desktop/webdeploy/space-invaders-clone/src/SceneManager.cpp"
  "C:/Users/brend/Desktop/webdeploy/space-invaders-clone/src/main.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "C:/Users/brend/Desktop/webdeploy/space-invaders-clone/build-emc/CMakeFiles/cmake.verify_globs")
endif()