cmake_minimum_required(VERSION 3.23)
project(budget_tracker)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(budget_tracker)
target_sources(budget_tracker
  PRIVATE
    src/main.c
)

add_executable(tracker_test)
target_sources(tracker_test
  PRIVATE
    test/test.cpp
    src/database.c
)
target_link_libraries(
  tracker_test
  GTest::gtest_main
)
target_include_directories(tracker_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

include(GoogleTest)
gtest_discover_tests(tracker_test)
