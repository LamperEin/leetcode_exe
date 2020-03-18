#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <ctime>
#include <cmath>

using namespace std;

template<typename Item>
class MaxHeap {

private:
    Item* data_;
    int count_;
    int capacity_;
    void shiftUp(int idx) {
        while(data_[idx/2] < data_[idx]) {
            swap(data_[idx/2], data_[idx]);
            idx /= 2;
        }
    }

public:
    MaxHeap(int capacity) {
        data_ = new Item[capacity+1];
        count_ = 0;
        capacity_ = capacity;
    }

    ~MaxHeap() {
        delete [] data_;
    }

    int size() {
        return count_;
    }

    bool isEmpty() {
        return count_==0;
    }

    void insert(Item item) {
        assert(count_+1 <= capacity_);
        data_[count_+1] = item;
        count_++;
        shiftUp(count_);
    }
};


int main() {
    MaxHeap<int> maxheap = MaxHeap<int>(100);
    cout << maxheap.size() << endl;

    srand(time(NULL));
    
    return 0;
}