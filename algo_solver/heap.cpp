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

bool isLegal(int a, int b, int c) {
    vector<int> data {a, b, c};
    sort(data.begin(), data.end());
    a = data[0], b = data[1], c = data[2];
    if(c < a+b && a > c-b)
        return true;
    return false;
}

int main() {
    int n = 0;
    cin >> n;
    if(n < 3) cout << 0 << endl;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];
    int ans = 0;
    for(int i = 0; i <= nums.size()-3; i++) {
        for(int j = i+1; j <= nums.size()-2; j++) {
            for(int k = j+1; k <= nums.size()-1; k++) {
                if(isLegal(nums[i], nums[j], nums[k]))
                    ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
