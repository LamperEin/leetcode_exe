#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

/** leetcode-739 每日温度
 *  input: [73, 74, 75, 71, 69, 72, 76, 73]
 *  output:[1, 1, 1, 4, 2, 1, 1, 0, 0]
 *  对应位置的输出是需要再等待多久， 温度才会超过该天温度的天数
 */
vector<int> dailyTemperatures(vector<int>& T) {
    stack<int> tmp;
    vector<int> ans(T.size());
    for(int i = T.size()-1; i >= 0; i--) {
        while(!tmp.empty() && T[i] >= T[tmp.top()]) 
            tmp.pop();
        if(tmp.empty()) ans[i] = 0;
        else ans[i] = tmp.top()-i;
        tmp.push(i);
    }
    return ans;
}

/** leetcode-150 逆波兰表达式求值
 *  input: ["2", "1", "+", "3", "*"] ->output: 9
 *   ((2+1)*3) = 9
 */
int evalRPN(vector<string>& tokens) {
    stack<int> sk;
    for(string s : tokens) {
        int op1, op2;
        bool sign = false;
        if(s == "+") {
            op2 = sk.top(); sk.pop();
            op1 = sk.top(); sk.pop();
            sk.push(op1+op2);
            sign = true;
        }
        if(s == "-") {
            op2 = sk.top(); sk.pop();
            op1 = sk.top(); sk.pop();
            sk.push(op1-op2);
            sign = true;
        }
        if(s == "*") {
            op2 = sk.top(); sk.pop();
            op1 = sk.top(); sk.pop();
            sk.push(op1*op2);
            sign = true;
        }
        if(s == "/") {
            op2 = sk.top(); sk.pop();
            op1 = sk.top(); sk.pop();
            sk.push(op1/op2);
            sign = true;
        }
        if(!sign)
            sk.push(atoi(s.c_str()));
    }
    return sk.top();
}

/** leetcode-84 柱状图中最大的矩形 leetcode-85类似
 *  @param: a vector of non-negative integers stands for the bar height
 *  @return: the largest rectangle area in the histogram
 */
int largestRectangleArea(vector<int>& heights) {
    int ans = 0;
    stack<int> sk;
    heights.push_back(-1);
    sk.push(0);
    for(int i = 0; i < heights.size(); i++) {
        while(!sk.empty() && heights[sk.top()] >= heights[i]) {
            int cur = sk.top();
            sk.pop();
            int w = sk.empty() ? i : i-sk.top()-1;
            ans = max(ans, w*heights[cur]);
        }
        sk.push(i);
    }
    return ans;
}

int main() {
    vector<int> a = {5, 4, 3, 2, 9, 10, 0, 7, 8, 4, 6};
    cout << largestRectangleArea(a) << endl;
    return 0;
}