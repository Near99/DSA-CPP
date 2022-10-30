#include <iostream>

#ifndef __PRIORITY_QUEUE__
#define __PRIORITY_QUEUE__

namespace pq {

class PriorityQueue {
   public:
    explicit PriorityQueue(int capacity)
        : queue_(new int[capacity]()), capacity_(capacity), size_(0) {}

    void insert(int val);

    int capacity();

    int size();

    int min();

    int extractMin();

    void makeHeap();

    void heapSort();

    bool empty();

    bool full();

   private:
    int* queue_;
    int capacity_;
    int size_;
};

int pq::PriorityQueue::capacity() { return capacity_; }

};  // namespace pq
#endif