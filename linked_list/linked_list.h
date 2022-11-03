#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <iostream>
#include <list>

namespace ll {

template <class T>
class Node {
   public:
    Node(const T& value) : value_(value), next_(nullptr) {}
    ~Node() {}

    T value_;
    Node<T>* next_;
};

template <class T>
class LinkedList {
   public:
    LinkedList() : head_(nullptr) {}

    void insertFront(const T value);

    void insertBack(const T value);

    Node<T> remove(const T value);

    Node<T> removeFront();

    Node<T> removeEnd();

    void reverse();

    void print();

    bool empty() const;

    int size();

   private:
    Node<T>* head_;

    void insert_front_(Node<T>** head, const T value);

    void reverse_(Node<T>** head);
};

template <class T>
void ll::LinkedList<T>::insertFront(const T value) {
    insert_front_(&head_, value);
}

template <class T>
void ll::LinkedList<T>::reverse() {
    reverse_(&head_);
}

template <class T>
bool ll::LinkedList<T>::empty() const {
    return head_ == nullptr;
}

template <class T>
void ll::LinkedList<T>::print() {
    Node<T>* h = head_;
    while (h != nullptr) {
        std::cout << h->value_ << std::endl;
        h = h->next_;
    }
}

template <class T>
int ll::LinkedList<T>::size() {
    int counter = 0;
    while (head_ != nullptr) {
        counter++;
        head_ = head_->next_;
    }
    return counter;
}

template <class T>
void ll::LinkedList<T>::insert_front_(Node<T>** head, const T value) {
    Node<T>* new_node = new Node<T>(value);
    new_node->next_ = (*head);
    (*head) = new_node;
}

template <class T>
void ll::LinkedList<T>::reverse_(Node<T>** head) {
    Node<T>*pre = nullptr, *curr = *head, *next = nullptr;
    while (curr != nullptr) {
        next = curr->next_;
        curr->next_ = pre;
        pre = curr;
        curr = next;
    }
    (*head) = pre;
}
}  // namespace ll
#endif