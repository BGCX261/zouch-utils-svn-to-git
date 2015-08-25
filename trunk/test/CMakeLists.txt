add_definitions(-std=c++0x -fsigned-char -freg-struct-return -Wall -W)

set(CMAKE_CXX_FLAGS_DEBUG "-g -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

include_directories(inc)
include_directories(src)

# list of source files
set(
  source_files
  src/main.cpp
)

add_executable(
  run
  ${source_files}
)

target_link_libraries(
  run
  ZouchUtils
)