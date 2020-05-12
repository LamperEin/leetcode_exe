#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Queue {
    private:
        vector<int> q_;
    public:
        void push(int n) { 
            q_.push_back(n);
        }
        int pop() {
            if(q_.empty())
                return -1;
            int data = q_.front();
            reverse(q_.begin(), q_.end());
            q_.pop_back();
            reverse(q_.begin(), q_.end());
            return data;
        }

        int top() {
            if(q_.empty())
                return -1;
            return q_.front();
        }

        int size() {
            return q_.size();
        }

        void clear() {
            q_.clear();
        }
};

int main() {
    int n = 0;
    cin >> n;
    Queue q;
    while(n--) {
        int t = 0;
        cin >> t;
        while(t--) {
            string op;
            int num = 0;
            cin >> op;
            if(op == "PUSH") {
                cin >> num;
                q.push(num);
            }
            if(op == "TOP") {
                cout << q.top() << endl;
            }
            if(op == "POP") {
                cout << q.pop() << endl;
            }
            if(op == "SIZE") cout << q.size() << endl;
            if(op == "CLEAR") q.clear();
        }
    }
    return 0;
}