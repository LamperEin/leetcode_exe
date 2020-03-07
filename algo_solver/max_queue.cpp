#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class MaxQueue {
private:
    struct internalData {
        int value;
        int index;
    };
    deque<internalData> q_;
    deque<internalData> maximums;
    int current_index;

public:
    MaxQueue() {
        current_index = 0;
    }

    int max_value() {
        if(maximums.empty())
            return -1;
        return maximums.front().value;
    }

    void push_back(int value) {
        while(!maximums.empty() && value >= maximums.back().value)
            maximums.pop_back();
        internalData idata = {value, current_index};
        q_.push_back(idata);
        maximums.push_back(idata);

        current_index++;
    }

    int pop_front() {
        if(q_.empty())
        return -1;
        if(maximums.front().value == q_.front().value)
            maximums.pop_front();
        int res = q_.front().value;
        q_.pop_front();
        return res;
    }
};

int main() {

    return 0;
}