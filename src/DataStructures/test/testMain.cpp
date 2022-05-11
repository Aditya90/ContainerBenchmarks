#include "DataStructures/CustomDataStructures.h"

#include <gtest/gtest.h>

using namespace std;
class QueueTest : public ::testing::Test
{
protected:
    // void SetUp() override {}

    // void TearDown() override {}
    const size_t testCapacity_{3};
    Queue<int> testQueue_{testCapacity_};
};

TEST_F(QueueTest, When_DefaultConstruction_Then_AssertInitialSizeCapacity)
{
    EXPECT_EQ(testCapacity_, testQueue_.getCapacity());
    EXPECT_EQ(0, testQueue_.getSize());
}

TEST_F(QueueTest, When_Pop_Then_CheckValueAndSizeChange)
{
    testQueue_.push_back(1);
    testQueue_.push_back(2);
    testQueue_.push_back(3);
    EXPECT_EQ(3, testQueue_.getSize());
    EXPECT_EQ(1, testQueue_.pop_front());
    EXPECT_EQ(2, testQueue_.getSize());
}
TEST_F(QueueTest, When_PushMoreThanCapacity_Then_IncreaseQueueCapacity)
{
    for (size_t i = 0; i < testCapacity_; i++)
    {
        testQueue_.push_back(i + 1);
    }
    EXPECT_EQ(testCapacity_, testQueue_.getCapacity());

    testQueue_.push_back(testCapacity_);

    EXPECT_GT(testQueue_.getCapacity(), testCapacity_);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}