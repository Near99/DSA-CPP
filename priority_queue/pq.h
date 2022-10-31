#include <iostream>

#ifndef __PRIORITY_QUEUE__
#define __PRIORITY_QUEUE__

namespace pq {
/**
 * @brief indices calculation formula.
 * heapify starting index: (n/2)-1
 * children: 2i+1, 2i+2
 * parent: (i-1)/2
 */
class PriorityQueue {
   public:
    explicit PriorityQueue(int capacity)
        : queue_(new int[capacity]()), capacity_(capacity), size_(0) {}

    void insert(int value);

    int max();

    int extractMax();

    int capacity();

    int size();

    bool empty();

    bool full();

    void heapSort(int* arr, int n);

    void print() {
        for (int i = 0; i < size_; i++) {
            std::cout << queue_[i] << std::endl;
        }
    }

   private:
    int* queue_;
    int capacity_;
    int size_;

    void heapify_(int* arr, int i, int n);

    void siftUp_(int index);

    void siftDown_(int index);
};

void pq::PriorityQueue::insert(int value) {
    if (size_ == capacity_) {
        std::cout << "Full queue!" << std::endl;
        return;
    }
    queue_[size_++] = value;
    siftUp_(size_ - 1);
}

int pq::PriorityQueue::max() {
    if (empty()) {
        std::cout << "Empty queue!" << std::endl;
        exit(EXIT_FAILURE);
    }
    return queue_[0];
}

int pq::PriorityQueue::extractMax() {
    if (empty()) {
        std::cout << "Empty queue!" << std::endl;
        exit(EXIT_FAILURE);
    }
    int max = queue_[0];
    queue_[0] = queue_[--size_];
    siftDown_(0);
    return max;
}

int pq::PriorityQueue::capacity() { return capacity_; }

int pq::PriorityQueue::size() { return size_; }

bool pq::PriorityQueue::empty() { return size_ == 0; }

bool pq::PriorityQueue::full() { return size_ == capacity_; }

void pq::PriorityQueue::heapSort(int* arr, int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify_(arr, i, n);
    }
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify_(arr, 0, i);
    }
}

void pq::PriorityQueue::heapify_(int* arr, int index, int n) {
    int max = index;
    for (int i = 1; i <= 2; i++) {
        int c = (2 * index) + i;
        if (c < n) {
            if (arr[max] < arr[c]) {
                max = c;
            }
        }
    }
    if (max != index) {
        int temp = arr[max];
        arr[max] = arr[index];
        arr[index] = temp;
        heapify_(arr, max, n);
    }
}

void pq::PriorityQueue::siftUp_(int index) {
    if (index == 0) return;
    int parent = (index - 1) / 2;
    if (queue_[index] > queue_[parent]) {
        int temp = queue_[parent];
        queue_[parent] = queue_[index];
        queue_[index] = temp;
        siftUp_(parent);
    }
}

void pq::PriorityQueue::siftDown_(int index) {
    int max = index;
    for (int i = 1; i <= 2; i++) {
        int c = (2 * index) + i;
        if (c < size_) {
            if (queue_[max] < queue_[c]) {
                max = c;
            }
        }
    }
    if (max != index) {
        int temp = queue_[max];
        queue_[max] = queue_[index];
        queue_[index] = temp;
        siftDown_(max);
    }
}
};  // namespace pq
#endif
