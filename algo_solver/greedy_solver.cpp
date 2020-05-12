#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int cuttingRope(int n) {
    if(n <= 3) return n-1;
    int m = 1;
    while(n>4) {
        m *= 3;
        n -= 3;
    }
    return m*n;
}

/** leetcode-55 跳跃游戏
 *  input：[2, 3, 1, 1, 4] output: true
 *  input: [3, 2, 1, 0, 4] output: false
 */
bool canJump(vector<int>& nums) {
    int n = nums.size();
    int rightmost = 0;
    for(int i = 0; i < n; i++) {
        if(i <= rightmost) {
            rightmost = max(rightmost, i+nums[i]);
            if(rightmost >= n-1) return ture;
        }
    }
    return false;
}

/** leetcode-122 买卖股票的最佳时机II
 *   @input: [7,1,5,3,6,4] -> @output: 7
 *   @input: [1,2,3,4,5] -> @output:4
 */
int maxProfit2(vector<int>& prices) {
    int ans = 0, minx=prices[0], tmpmax = 0;
    for(int i=1; i<prices.size(); i++) {
        if(prices[i] < minx) minx = prices[i];
        if(prices[i] - minx > tmpmax) tmpmax = prices[i] - minx;
        else {
            ans += tmpmax;
            tmpmax = 0;
            minx = prices[i];
        }
    }
    ans += tmpmax == 0 ? 0 : tmpmax;
    return ans;
}

/** leetcode-45 跳跃游戏II
 *  @param: a vector of nums
 *  @return: the smallest jump times
 */
int jump(vector<int>& nums) {
    int n = nums.size();
    int rightmost = 0;
    int cnt = 0, end = 0;
    for(int i = 0; i < n-1; i++) {
        rightmost = max(rightmost, i+nums[i]);
        if(i == end) {
            end = rightmost;
            cnt++;
        } 
    }
    return cnt;
}

int main() {


    return 0;
}