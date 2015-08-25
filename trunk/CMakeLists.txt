project(ZouchUtils)
cmake_minimum_required(VERSION 2.8)

set(-DROOT_DIR ${PROJECT_ROOT_DIR})

find_package(Boost 1.51 REQUIRED)

include_directories(
  lib/inc
  lib/src
  test/inc
  test/src
  ${Boost_INCLUDE_DIR}
)

link_directories(${Boost_LIBRARY_DIRS})

add_subdirectory(lib)
add_subdirectory(test build)