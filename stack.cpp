#include "stack.h"

Node::Node(int32_t value, Node *previous) : value(value), previous(previous){};

Stack::Stack() {
    size_ = 0;
    head_ = nullptr;
};

void Stack::Pop() {
    if (size_ > 0) {
        Node *tmp = head_;
        head_ = head_->previous;
        delete tmp;
        size_--;
    }
};

void Stack::Clear() {
    while (head_ != nullptr) {
        Pop();
    }
    size_ = 0;
};

Stack::~Stack() {
    Clear();
    delete head_;
}

void Stack::Push(int32_t value) {
    size_++;
    Node *tmp = new Node(value, head_);
    head_ = tmp;
};

int32_t Stack::Top() const {
    return head_->value;
};

int32_t Stack::Size() const {
    return size_;
};

bool Stack::Empty() const {
    return size_ == 0;
};