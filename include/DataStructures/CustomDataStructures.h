// Implement a standard queue, map, list, set, stack, heap
/*
Properties of a queue
1. First In First Out
2. If queue is full(size=capacity), re-allocate

Sample cases
A(3)
A.push_back(1) // (1),-,-; size -1; cap - 3
A.push_back(2,3) // (1),2,3; size - 3; cap - 3
A.pop()// -,(2),3 ; size = 2; cap- 3
A.push_back(4) // 4,(2),3
A.push_back(5) // -, (2), 3, 4, -, -

*/
#include <memory>
#include <iostream>
#include <shared_mutex>

template <typename T>
class Queue
{
public:
    Queue()
    {
        front_ = 0;
        size_ = 0;
        capacity_ = 10;
        queueData_ = std::make_unique<T[]>(capacity_);
    }

    explicit Queue(size_t capacity)
    {
        front_ = 0;
        size_ = 0;
        capacity_ = capacity;
        queueData_ = std::make_unique<T[]>(capacity_);
    }
    /**
     * @brief Push a value to the front of the queue
     * @param val Value to push into the queue
     */
    void push_back(const T &val);

    /**
     * @brief Get the value from the front of the queue and pop it
     *
     * @return T Value at the front of the queue
     */
    T pop_front();

    /**
     * @brief Print information about the queue
     *
     */
    void print();

    /**
     * @brief Get the Size object
     *
     * @return size_t Size of the queue
     */
    size_t getSize()
    {
        std::shared_lock lock(queueDataMutex_);
        return size_;
    }

    /**
     * @brief Get the Capacity object
     *
     * @return size_t Capacity of the queue
     */
    size_t getCapacity()
    {
        std::shared_lock lock(queueDataMutex_);
        return capacity_;
    }

private:
    std::unique_ptr<T[]> queueData_;
    size_t front_{0};
    size_t size_{0};
    size_t capacity_{10};

    std::shared_mutex queueDataMutex_;

    /**
     * @brief Resize the queue to twice its existing capacity
     */
    void resizeQueue()
    {
        std::unique_ptr<T[]> newQueueData(new T[capacity_ * 2]);

        std::move(queueData_.get() + front_, queueData_.get() + capacity_, newQueueData.get() + front_);
        std::move(queueData_.get(), queueData_.get() + front_, newQueueData.get() + capacity_);

        queueData_.swap(newQueueData);
        capacity_ = capacity_ * 2;
    }

    /**
     * @brief Find the next index in the queue data structure to fill a value into
     *
     * @return size_t Index location to fill
     */
    size_t findNextIndexToFill()
    {
        size_t nextIndex = (front_ + size_) % capacity_;
        return nextIndex;
    }

    /**
     * @brief Increment the index pointing to the front of the queue
     *
     */
    void incrementFront()
    {
        front_ = (front_ + 1) % capacity_;
    }
};

template <typename T>
void Queue<T>::push_back(const T &val)
{
    std::unique_lock lock(queueDataMutex_);
    if (size_ == capacity_)
    {
        resizeQueue();
    }

    size_t nextIndex = findNextIndexToFill();

    queueData_[nextIndex] = val;
    size_++;
}

template <typename T>
T Queue<T>::pop_front()
{
    std::unique_lock lock(queueDataMutex_);
    if (size_ == 0)
    {
        throw std::runtime_error("Empty queue");
    }
    else
    {
        T retVal = queueData_[front_];
        incrementFront();
        size_--;
        return retVal;
    }
}

template <typename T>
void Queue<T>::print()
{
    std::shared_lock lock(queueDataMutex_);

    std::cout << "Data: ";
    for (size_t index = 0; index < capacity_; index++)
    {
        std::cout << queueData_[index] << " ";
    }
    std::cout << std::endl;

    std::cout << "Front: " << front_ << std::endl;
    std::cout << "Size: " << size_ << std::endl;
}