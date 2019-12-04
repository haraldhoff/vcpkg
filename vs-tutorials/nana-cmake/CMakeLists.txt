cmake_minimum_required(VERSION 3.9)

#======= Establish toolchain (must be done before specifying project) =========#

if (WIN32)
  if (NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    if (NOT DEFINED ENV{VCPKG_ROOT})
      set(ENV{VCPKG_ROOT} "C:/opt/vcpkg")
    endif()
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
  endif()
endif()

if (DEFINED CMAKE_TOOLCHAIN_FILE)
  message(" [INFO] CMAKE_TOOLCHAIN_FILE = ${CMAKE_TOOLCHAIN_FILE}")
endif()


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
