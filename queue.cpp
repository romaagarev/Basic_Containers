#include "queue.h"

Node::Node(int32_t value, Node *next) : value(value), next(next){};

Queue::Queue() {
    size_ = 0;
    tail_ = nullptr;
    front_ = nullptr;
};

void Queue::Pop() {
    if (size_ > 0) {
        Node *tmp = front_;
        front_ = tmp->next;
        delete tmp;
    }
    size_--;
    if (size_ == 0) {
        tail_ = nullptr;
    }
};

void Queue::Clear() {
    while (size_ > 0) {
        Pop();
    }
};

Queue::~Queue() {
    Clear();
};

void Queue::Push(int32_t value) {
    Node *tmp = new Node(value, nullptr);
    if (size_ > 0) {
        tail_->next = tmp;
    } else {
        front_ = tmp;
    }
    tail_ = tmp;
    size_++;
};

int32_t Queue::Front() const {
    return front_->value;
};

int32_t Queue::Size() const {
    return size_;
};

bool Queue::Empty() const {
    return size_ == 0;
};
