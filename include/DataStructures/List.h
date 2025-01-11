

class List
{
};
template <typename T>
class List
{
public:
    List()
    {
        head_ = nullptr;
        tail_ = nullptr;
        size_ = 0;
    }

    ~List()
    {
        Node *current = head_;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }

    void push_back(const T &value)
    {
        Node *newNode = new Node{value};
        if (head_ == nullptr)
        {
            head_ = newNode;
            tail_ = newNode;
        }
        else
        {
            tail_->next = newNode;
            newNode->prev = tail_;
            tail_ = newNode;
        }
        size_++;
    }

    void push_front(const T &value)
    {
        Node *newNode = new Node{value};
        if (head_ == nullptr)
        {
            head_ = newNode;
            tail_ = newNode;
        }
        else
        {
            newNode->next = head_;
            head_->prev = newNode;
            head_ = newNode;
        }
        size_++;
    }

    T pop_back()
    {
        if (tail_ == nullptr)
        {
            throw std::runtime_error("List is empty");
        }

        T value = tail_->data;
        Node *oldTail = tail_;

        if (head_ == tail_)
        {
            head_ = nullptr;
            tail_ = nullptr;
        }
        else
        {
            tail_ = tail_->prev;
            tail_->next = nullptr;
        }

        delete oldTail;
        size_--;
        return value;
    }

    T pop_front()
    {
        if (head_ == nullptr)
        {
            throw std::runtime_error("List is empty");
        }

        T value = head_->data;
        Node *oldHead = head_;

        if (head_ == tail_)
        {
            head_ = nullptr;
            tail_ = nullptr;
        }
        else
        {
            head_ = head_->next;
            head_->prev = nullptr;
        }

        delete oldHead;
        size_--;
        return value;
    }

    size_t size() const
    {
        return size_;
    }

    bool empty() const
    {
        return size_ == 0;
    }

private:
    struct Node
    {
        T data;
        Node *next{nullptr};
        Node *prev{nullptr};

        Node(const T &value) : data(value) {}
    };

    Node *head_;
    Node *tail_;
    size_t size_;
};
