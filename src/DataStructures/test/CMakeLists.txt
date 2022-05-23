add_executable(DataStructuresTest
               ./testMain.cpp)

target_link_libraries(
  DataStructuresTest
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(DataStructuresTest)
