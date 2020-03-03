#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

class MyCircularQueue {
private:
    vector<int> data_;
    int head_;
    int tail_;
    int size_;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data_.resize(k);
        head_ = -1;
        tail_ = -1;
        size_ = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            head_ = 0;
        }
        tail_ = (tail_ + 1) % size_;
        data_[tail_] = value;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        if (head_ == tail_) {
            head_ = -1;
            tail_ = -1;
            return true;
        }
        head_ = (head_ + 1) % size_;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return data_[head_];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return data_[tail_];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return head_ == -1;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return ((tail_ + 1) % size_) == head_;
    }
};

int main() {

    return 0;
}