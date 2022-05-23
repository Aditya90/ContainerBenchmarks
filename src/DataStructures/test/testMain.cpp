#include "DataStructures/CustomDataStructures.h"

#include <gtest/gtest.h>

#include <thread>
#include <algorithm>

using namespace std;
class QueueSingleThreadedTest : public ::testing::Test
{
protected:
    // void SetUp() override {}

    // void TearDown() override {}
    const size_t testCapacity_{3};
    Queue<int> testQueue_{testCapacity_};
};

TEST_F(QueueSingleThreadedTest, When_DefaultConstruction_Then_AssertInitialSizeCapacity)
{
    EXPECT_EQ(testCapacity_, testQueue_.getCapacity());
    EXPECT_EQ(0, testQueue_.getSize());
}

TEST_F(QueueSingleThreadedTest, When_Pop_Then_CheckValueAndSizeChange)
{
    testQueue_.push_back(1);
    testQueue_.push_back(2);
    testQueue_.push_back(3);
    EXPECT_EQ(3, testQueue_.getSize());
    EXPECT_EQ(1, testQueue_.pop_front());
    EXPECT_EQ(2, testQueue_.getSize());
}

TEST_F(QueueSingleThreadedTest, When_MoreEntriesThanCapacity_Then_PushToStaleLocations)
{
    testQueue_.push_back(1);
    testQueue_.push_back(2);
    testQueue_.push_back(3);

    EXPECT_EQ(1, testQueue_.pop_front());
    EXPECT_EQ(2, testQueue_.pop_front());

    testQueue_.push_back(4);
    testQueue_.push_back(5);

    EXPECT_EQ(3, testQueue_.pop_front());
    EXPECT_EQ(4, testQueue_.pop_front());
    EXPECT_EQ(1, testQueue_.getSize());
}

TEST_F(QueueSingleThreadedTest, When_PushMoreThanCapacity_Then_IncreaseQueueCapacity)
{
    for (size_t i = 0; i < testCapacity_; i++)
    {
        testQueue_.push_back(i + 1);
    }
    EXPECT_EQ(testCapacity_, testQueue_.getCapacity());

    testQueue_.push_back(testCapacity_);

    EXPECT_GT(testQueue_.getCapacity(), testCapacity_);
}

TEST_F(QueueSingleThreadedTest, When_PopMoreThanSize_Then_ThrowException)
{
    testQueue_.push_back(1);
    EXPECT_EQ(1, testQueue_.pop_front());
    EXPECT_ANY_THROW(testQueue_.pop_front());
}

class QueueMultiThreadedTest : public ::testing::Test
{
protected:
    // void SetUp() override {}

    // void TearDown() override {}
    const size_t testCapacity_{3};
    Queue<int> testQueue_{testCapacity_};

    static void writeToQueue(Queue<int> &testQueue, std::vector<int> valuesToWrite)
    {
        for (const auto &i : valuesToWrite)
        {
            testQueue.push_back(i);
            std::this_thread::sleep_for(1ms);
        }
    }
    static void readFromQueue(Queue<int> &testQueue, size_t numberOfValuesToRead, std::vector<int> &valuesReadOut)
    {
        for (size_t i = 0; i < numberOfValuesToRead; i++)
        {
            valuesReadOut.push_back(testQueue.pop_front());
            std::this_thread::sleep_for(1ms);
        }
    }
};

TEST_F(QueueMultiThreadedTest, When_WriteFromOneThread_Then_CanReadFromAnotherThread)
{
    std::vector<int> valuesToWrite{1, 2, 3, 4, 5};
    std::vector<int> valuesReadOut;

    {
        // Push values from one thread to the queue
        std::jthread thread1(this->writeToQueue, std::ref(testQueue_), valuesToWrite);

        // Give the previous thread some headway
        std::this_thread::sleep_for(1ms);

        // Access values of the queue from another thread in parallel
        std::jthread thread2(this->readFromQueue, std::ref(testQueue_), valuesToWrite.size(), std::ref(valuesReadOut));
    }

    // Compare values after both threads finish execution
    EXPECT_EQ(valuesReadOut, valuesToWrite);
}

TEST_F(QueueMultiThreadedTest, When_WriteFrom2Threads_Then_NoCorruptionsOnRead)
{
    std::vector<int> valuesToWriteThread1{1, 2, 3, 4, 5};
    std::vector<int> valuesToWriteThread2{6, 7, 8};
    std::vector<int> valuesReadOut;

    {
        // Push values from one thread to the queue
        std::jthread thread1(this->writeToQueue, std::ref(testQueue_), valuesToWriteThread1);
        std::jthread thread2(this->writeToQueue, std::ref(testQueue_), valuesToWriteThread2);

        // Give the previous thread some headway
        std::this_thread::sleep_for(1ms);

        // Access values of the queue from another thread in parallel
        std::jthread thread3(this->readFromQueue, std::ref(testQueue_), valuesToWriteThread1.size() + valuesToWriteThread2.size(), std::ref(valuesReadOut));
    }

    // Update thread 1 data to have both thread 1 and thread 2 values
    valuesToWriteThread1.insert(valuesToWriteThread1.end(), valuesToWriteThread2.begin(), valuesToWriteThread2.end());

    EXPECT_TRUE(std::is_permutation(valuesReadOut.begin(), valuesReadOut.end(), valuesToWriteThread1.begin()));
}

TEST_F(QueueMultiThreadedTest, When_WriteFrom2ThreadsReadFrom2Threads_Then_NoCorruptionsOnRead)
{
    std::vector<int> valuesToWriteThread1{1, 2, 3, 4, 5};
    std::vector<int> valuesToWriteThread2{6, 7, 8};
    std::vector<int> valuesReadOutThread3;
    std::vector<int> valuesReadOutThread4;

    {
        // Push values from one thread to the queue
        std::jthread thread1(this->writeToQueue, std::ref(testQueue_), valuesToWriteThread1);
        std::jthread thread2(this->writeToQueue, std::ref(testQueue_), valuesToWriteThread2);

        // Give the previous thread some headway
        std::this_thread::sleep_for(1ms);

        // Access values of the queue from another thread in parallel
        std::jthread thread3(this->readFromQueue, std::ref(testQueue_), valuesToWriteThread1.size(), std::ref(valuesReadOutThread3));
        std::jthread thread4(this->readFromQueue, std::ref(testQueue_), valuesToWriteThread2.size(), std::ref(valuesReadOutThread4));
    }

    // Update thread 1 data to have both thread 1 and thread 2 values, and thread 3 to have
    // data read in thread 3 and thread 4
    valuesToWriteThread1.insert(valuesToWriteThread1.end(), valuesToWriteThread2.begin(), valuesToWriteThread2.end());
    valuesReadOutThread3.insert(valuesReadOutThread3.end(), valuesReadOutThread4.begin(), valuesReadOutThread4.end());

    EXPECT_TRUE(std::is_permutation(valuesReadOutThread3.begin(), valuesReadOutThread3.end(), valuesToWriteThread1.begin()));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}