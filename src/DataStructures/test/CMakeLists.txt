add_executable(QueueTest
               ./QueueTest.cpp)

target_link_libraries(
  QueueTest
  gtest_main
)

add_executable(GraphTest
               ./GraphTest.cpp)

target_link_libraries(
  GraphTest
  gtest_main
)


include(GoogleTest)
gtest_discover_tests(QueueTest)
gtest_discover_tests(GraphTest)
