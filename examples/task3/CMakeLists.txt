cmake_minimum_required(VERSION 3.10)
project(class4)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-fPIC")

include_directories("../..")

set(INCREMENTAL_SFM_SOURCES
        task3-1_test_incremental_sfm.cc defines.h functions.cc functions.h)
add_executable(task3-1_incremental_sfm ${INCREMENTAL_SFM_SOURCES})
target_link_libraries(task3-1_incremental_sfm sfm util core features)

