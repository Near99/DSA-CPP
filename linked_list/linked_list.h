#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <iostream>
#include <list>

namespace ll {

template <class T>
class Node {
   public:
    Node(const T& value) : value_(value), next_(nullptr) {}
    Node() : value_(0), next_(nullptr) {}
    ~Node() {}

    T value_;
    Node<T>* next_;
};

template <class T>
class LinkedList {
   public:
    LinkedList() : head_(nullptr) {}

    ~LinkedList();

    void insertFront(const T value);

    void insertBack(const T value);

    Node<T> remove(const T value);

    Node<T> removeFront();

    Node<T> removeEnd();

    void erase();

    void reverse();

    void print();

    bool empty() const;

    int size();

   private:
    Node<T>* head_;

    void insert_front_(Node<T>** head, const T value);

    void insert_back_(Node<T>** head, const T value);

    Node<T> remove_front_(Node<T>** head);

    Node<T> remove_end_(Node<T>** head);

    void erase_(Node<T>** head);

    void reverse_(Node<T>** head);
};

template <class T>
ll::LinkedList<T>::~LinkedList() {
    Node<T>*pre = nullptr, *curr = head_;
    while (curr != nullptr) {
        pre = curr;
        curr = curr->next_;
        delete pre;
    }
    delete head_;
}

template <class T>
void ll::LinkedList<T>::insertFront(const T value) {
    insert_front_(&head_, value);
}

template <class T>
void ll::LinkedList<T>::insertBack(const T value) {
    insert_back_(&head_, value);
}

template <class T>
Node<T> ll::LinkedList<T>::removeFront() {
    return remove_front_(&head_);
}

template <class T>
Node<T> ll::LinkedList<T>::removeEnd() {
    return remove_end_(&head_);
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
void ll::LinkedList<T>::erase() {
    erase_(&head_);
}

template <class T>
void ll::LinkedList<T>::print() {
    Node<T>* curr = head_;
    while (curr != nullptr) {
        std::cout << curr->value_ << std::endl;
        curr = curr->next_;
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
void ll::LinkedList<T>::insert_back_(Node<T>** head, const T value) {
    Node<T>* new_node = new Node<T>(value);
    if ((*head) == nullptr) {
        (*head) = new_node;
        return;
    }
    while ((*head)->next_ != nullptr) {
        head = &(*head)->next_;
    }
    (*head)->next_ = new_node;
}

template <class T>
Node<T> ll::LinkedList<T>::remove_front_(Node<T>** head) {
    if ((*head) == nullptr) {
        std::cout << "Empty list!" << std::endl;
        exit(EXIT_FAILURE);
    }
    Node<T>* node_to_delete = (*head);
    Node<T> node = *node_to_delete;
    (*head) = (*head)->next_;
    delete node_to_delete;
    return node;
}

template <class T>
Node<T> ll::LinkedList<T>::remove_end_(Node<T>** head) {
    if ((*head) == nullptr) {
        std::cout << "Empty list!" << std::endl;
        exit(EXIT_FAILURE);
    }
    Node<T>*node_to_delete = (*head), *pre = nullptr;
    Node<T> node;
    if ((*head)->next_ == nullptr) {
        (*head) = (*head)->next_;
        node = *node_to_delete;
        delete node_to_delete;
        return node;
    }
    while (node_to_delete->next_ != nullptr) {
        pre = node_to_delete;
        node_to_delete = node_to_delete->next_;
    }
    pre->next_ = node_to_delete->next_;
    node = *node_to_delete;
    delete node_to_delete;
    return node;
}

template <class T>
void ll::LinkedList<T>::erase_(Node<T>** head) {
    Node<T>*pre = nullptr, *curr = (*head);
    while (curr != nullptr) {
        pre = curr;
        curr = curr->next_;
        delete pre;
    }
    (*head) = nullptr;
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
