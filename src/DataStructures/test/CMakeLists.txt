add_executable(QueueTest
               ./QueueTest.cpp)

target_link_libraries(
  QueueTest
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(QueueTest)
