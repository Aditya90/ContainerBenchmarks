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
    void push_back(const T &val);
    T pop_front();

    void print();

    size_t getSize() { return size_; }
    size_t getCapacity() { return capacity_; }

private:
    std::unique_ptr<T[]> queueData_;
    size_t front_{0};
    size_t size_{0};
    size_t capacity_{10};

    void resizeQueue()
    {
        std::unique_ptr<T[]> newQueueData(new T[capacity_ * 2]);
        std::copy(queueData_.get() + front_, queueData_.get() + capacity_, newQueueData.get() + front_);
        std::copy(queueData_.get(), queueData_.get() + front_, newQueueData.get() + capacity_);

        queueData_.swap(newQueueData);
        capacity_ = capacity_ * 2;
    }

    size_t findNextIndexToFill()
    {
        size_t nextIndex = (front_ + size_) % capacity_;
        return nextIndex;
    }

    void incrementFront()
    {
        front_ = (front_ + 1) % capacity_;
    }
};

template <typename T>
void Queue<T>::push_back(const T &val)
{
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
    std::cout << "Data: ";
    for (size_t index = 0; index < capacity_; index++)
    {
        std::cout << queueData_[index] << " ";
    }
    std::cout << std::endl;

    std::cout << "Front: " << front_ << std::endl;
    std::cout << "Size: " << size_ << std::endl;
}