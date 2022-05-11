#include "DataStructures/CustomDataStructures.h"

#include <memory>
#include <iostream>

using namespace std;

void singleEntryPush()
{
    Queue<int> testQueue;
    testQueue.print();
    testQueue.push_back(1);

    // ostream outputStr;
    cout << testQueue.pop_front() << endl;

    testQueue.print();
}
void multipleEntryPush()
{
    Queue<int> testQueue(3);
    testQueue.print();
    testQueue.push_back(1);
    testQueue.push_back(2);
    testQueue.push_back(3);

    // ostream outputStr;
    cout << testQueue.pop_front() << endl;
    cout << testQueue.pop_front() << endl;

    testQueue.print();
}

void replacePoppedEntry()
{
    Queue<int> testQueue(3);
    testQueue.print();
    testQueue.push_back(1);
    testQueue.push_back(2);
    testQueue.push_back(3);

    // ostream outputStr;
    cout << testQueue.pop_front() << endl;
    testQueue.print();

    testQueue.push_back(4);

    testQueue.print();
}

void popMoreThanSize()
{
    Queue<int> testQueue(3);
    testQueue.print();
    testQueue.push_back(1);
    testQueue.push_back(2);
    testQueue.push_back(3);

    // ostream outputStr;
    cout << testQueue.pop_front() << endl;
    cout << testQueue.pop_front() << endl;
    cout << testQueue.pop_front() << endl;
    cout << testQueue.pop_front() << endl;

    testQueue.print();
}

void pushMoreThanCapacity()
{
    Queue<int> testQueue(3);
    testQueue.print();
    testQueue.push_back(1);
    testQueue.push_back(2);
    testQueue.push_back(3);
    testQueue.push_back(4);

    testQueue.print();
}

void pushMoreThanCapacityAfterPop()
{
    Queue<int> testQueue(3);
    testQueue.print();
    testQueue.push_back(1);
    testQueue.push_back(2);
    testQueue.push_back(3);
    static_cast<void>(testQueue.pop_front());

    testQueue.push_back(4);
    testQueue.print();

    testQueue.push_back(5);
    testQueue.print();
}
void wrapAroundFront()
{
    Queue<int> testQueue(3);
    testQueue.print();
    testQueue.push_back(1);
    testQueue.push_back(2);
    testQueue.push_back(3);

    // ostream outputStr;
    cout << testQueue.pop_front() << endl;
    cout << testQueue.pop_front() << endl;

    testQueue.push_back(4);
    testQueue.push_back(5);

    cout << testQueue.pop_front() << endl;

    testQueue.print();
}

void testQueue()
{

    // singleEntryPush();
    // cout << "------------" << endl;
    // multipleEntryPush();
    // cout << "------------" << endl;
    // replacePoppedEntry();
    // cout << "------------" << endl;
    // popMoreThanSize();
    // wrapAroundFront();
    pushMoreThanCapacity();
    cout << "------------" << endl;

    pushMoreThanCapacityAfterPop();
}

int main()
{
    try
    {
        testQueue();
    }
    catch (exception &e)
    {
        cerr << "Exception thrown: " << e.what() << endl;
        return -1;
    }

    return 1;
}