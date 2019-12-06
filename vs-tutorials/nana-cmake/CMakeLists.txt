cmake_minimum_required(VERSION 3.9)

#======= Establish toolchain (must be done before specifying project) =========#

if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
    message(" [INFO] VCPKG CMAKE_TOOLCHAIN_FILE = ${CMAKE_TOOLCHAIN_FILE}")
endif()


#======= Global Project Configuration =========#

project("nana-gui")
set(CMAKE_CXX_STANDARD 17)


#========== Targets Configurations ============#

## ==> Target: "nana-gui" - Executable: "nana-gui"

find_package(unofficial-fontconfig CONFIG REQUIRED)
find_package(unofficial-nana CONFIG REQUIRED)

add_executable("nana-gui"
  gui.cpp
  )

target_link_libraries("nana-gui" PRIVATE
  unofficial::nana::nana
  unofficial::fontconfig::fontconfig
  )

# Install directory relative to ${CMAKE_PREFIX_PATH}
install(TARGETS "nana-gui" DESTINATION ./bin)
