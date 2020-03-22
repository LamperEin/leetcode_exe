#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

int climbStairs(int n) {
    int a, b, i=2;
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    a = 1; b = 2;
    while (i < n) {
        int tmp = a;
        a = b;
        b = tmp + b;
        i++;
    }
    return b;
}

int maxProfit(vector<int>& prices) {
    if (prices.size() < 2)
        return 0;
    int xmin, maxprofits;
    xmin = prices[1]; maxprofits = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (xmin > prices[i-1]) 
            xmin = prices[i-1];
        if (prices[i] - xmin > maxprofits)
            maxprofits = prices[i] - xmin;
    }
    return maxprofits;
}

int maxSubArray(vector<int>& nums) {
    int maxsum, xmax;
    xmax = nums[0], maxsum = nums[0];
    for(int i = 1; i < nums.size(); i++) {
        xmax = max(nums[i], xmax+nums[i]);
        maxsum = max(maxsum, xmax);
    }

    return maxsum;
}

int minimumTotal(vector<vector<int>>& triangle) {
    int row = triangle.size()-1;
    vector<int> mini = triangle[row];
    for(int i = row-1; i >= 0; i--) {
        for(int j = 0; j < triangle[i].size(); j++) {
            mini[j] = triangle[i][j] + min(mini[j], mini[j+1]);
        }
    }

    return mini[0];
}

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, amount+1);
    dp[0] = 0;

    for(int i = 0; i < amount+1; i++) {
        for(int j = 0; j < coins.size(); j++) {
            if(i >= coins[j])
                dp[i] = min(dp[i-coins[j]]+1, dp[i]);
        }
    }
    if(dp[amount] == amount+1)
        return -1;

    return dp[amount];
}

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    vector<int> dp(n, 0);
    for(int i = 0; i < n; ++i) {
        dp[i] = 1;
        for(int j = 0; j < i; ++j) {
            if(nums[j] < nums[i])
                dp[i] = max(dp[i], dp[j]+1);
        }
    }

    return *max_element(dp.begin(), dp.end());
}

vector<double> twoSum(int n) {
    int dp[70];
    vector<double> ans;
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= 6; i++)
        dp[i] = 1;
    
    for(int i = 2; i <= n; i++) {
        for(int j = 6*i; j >= i; j--) {
            dp[j] = 0;
            for(int cur = 1; cur <= 6; cur++) {
                if(j - cur < i-1) break;
                dp[j] += dp[j-cur];
            }
        }
    }
    int all = pow(6, n);
    for(int i = n; i <= 6 * n; i++) 
        ans.push_back(dp[i]*1.0/all);
    return ans;
}

int uniquePaths(int m, int n) {

    return 0;
}

int getKthMagicNumber(int k) {
    int p3 = 0, p5 = 0, p7 = 0;
    int dp[k];
    dp[0] = 1;
    for(int i = 1; i < k; ++i) {
        dp[i] = min(dp[p3] * 3, min(dp[p5] * 5, dp[p7] * 7));
        if(dp[i] == dp[p3]*3) p3++;
        if(dp[i] == dp[p5]*5) p5++;
        if(dp[i] == dp[p7]*7) p7++;
    }
    return dp[k-1];
}
int maxValue(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();
    vector<int> dp(cols, 0);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            int left = 0, up = 0;
            if(i > 0) up = dp[j];
            if(j > 0) left = dp[j-1];
            dp[j] = max(up, left) + grid[i][j];
        }
    }
    return dp[cols-1];
}

int translateNum(int num) {
    string str = to_string(num);
    vector<int> dp(str.size()+1);
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i < dp.size(); i++) {
        dp[i] = dp[i-1];

        int num = stoi(str.substr(i-2, 2));
        if(num >= 10 && num <= 25)
            dp[i] += dp[i-2];
    }
    return dp.back();
}

int cuttingRope(int n) {
    if(n < 2) return 0;
    if(n == 2) return 1;
    if(n == 3) return 2;
    vector<int> dp(n+1 , 0);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    for(int i = 4; i <= n; i++) {
        int maxp = 0;
        for(int j = 1; j < i/2; j++){
           int product = dp[j] * dp[i-j];
            if(maxp < product)
                maxp = product;
            dp[i] = maxp;
        } 
    }
    return dp[n];
}

bool isMatch(string s, string p) {

    
}


int main() {
    cout << getKthMagicNumber(16) << endl;
    return 0;
}