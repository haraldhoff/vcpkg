cmake_minimum_required(VERSION 3.9)

set(CMAKE_TOOLCHAIN_FILE "C:/opt/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

#======= Global Project Configuration =========#

project(nanagui)
set(CMAKE_CXX_STANDARD 17)

#========== Targets Configurations ============#

## ==> Target: gui1 - Executable: gui1

find_package(unofficial-nana CONFIG REQUIRED)
add_executable(gui1 gui1.cpp)
target_link_libraries(gui1 PRIVATE
  unofficial::nana::nana fontconfig stdc++fs)

# Add target to run executable gui1 (similar to $ make run)
add_custom_target(run-gui1
  COMMAND gui1
  DEPENDS gui1
  WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)

# Install directory relative to ${CMAKE_PREFIX_PATH}
install(TARGETS gui1 DESTINATION ./bin)
