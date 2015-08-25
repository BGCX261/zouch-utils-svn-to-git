set(CMAKE_CXX_FLAGS_DEBUG "-g -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_definitions(-std=c++0x -fsigned-char -freg-struct-return -Wall -W)

include_directories(${BOOST_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIRS})

include_directories(inc)
include_directories(src)

# list of source files
set(
  source_files
  inc/csv_parser.hpp
  inc/pgm.hpp
  inc/utils.hpp
  src/csv_parser.cpp
  src/pgm.cpp
)

add_library(
  ZouchUtils
  STATIC
  ${source_files}
)