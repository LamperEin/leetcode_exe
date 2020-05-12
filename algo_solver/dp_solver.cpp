#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <climits>

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

    return false;
}

// dp[i][j] = min(dp[i-1][j]+grid[i][j], dp[i][j-1]+grid[i][j]) 
int minPathSum(vector<vector<int>>& grid) {
    int row = grid.size(), col = grid[0].size();
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
    dp[0][0] = grid[0][0];
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            int left = INT_MAX, up = INT_MAX;
            if(i >= 0)
                left = dp[i-1][j] + grid[i][j];
            if(j-1 >= 0)
                up = dp[i][j-1] + grid[i][j];
            if(i == 0 && j == 0)
                dp[i][j] = grid[0][0];
            else
                dp[i][j] = min(left, up);
        }
    }
    return dp[row-1][col-1];
}


/** 01背包问题
 *  dp[i+1][j]:= 从前i个物品中选出总重量不超过j的物品时的总价值的最大值
 *  dp[0][j] = 0   
 */
int solve(int n, int w, vector<int>& W, vector<int>& V) {
    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= w; j++) {
            if(j < W[i])
                dp[i+1][j] = dp[i][j];
            else
                dp[i+1][j] = max(dp[i][j], dp[i][j-W[i]]+V[i]);
        }
    }
}


/** 最长公共子序列
 *  input: s1="abcde", s2="ace" output: 3 
 */
int longestCommonSubsequence(string s1, string s2) {
    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(s1[i] == s2[j])
                dp[i+1][j+1] = dp[i][j]+1;
            else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
        }
    }
    return dp[n][m];
}

/** leetcode-887 鸡蛋掉落
 *  input: K=1, N=2 output: 2
 *  input: K=2, N=6 output: 3
 */
int superEggDrop(int K, int N) {
    vector<vector<int>> dp(K+1, vector<int>(N+1));
    
    int m = 0;
    while(dp[K][m] < N) {
        m++;
        for(int k = 1; k <= K; k++) 
            dp[k][m] = dp[k][m-1]+dp[k-1][m-1]+1;
    }
    return m;
}

/** leetcode-72 编辑距离
 *  input: s1="horse", s2="ros" output: 3
 *  horse -> rorse ('h' -> 'r')
 *  rorse -> rose (delete 'r')
 *  rose -> ros (delete 'e')
 */
int minDistance(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    if(m*n == 0) return m+n;
    vector<vector<int>> dp(m+1, vector<int>(n+1));   
    for(int i = 0; i <= m; ++i)
        dp[i][0] = i;
    for(int j = 0; j <= n; ++j)
        dp[0][j] = j;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]))+1;
        }
    }
    return dp[m][n];
}

/** leetcode-494 目标和
 *  问题可以转换成找到一个正数集P，其和的两倍等于目标和+序列总和
 *  01背包问题
 *  2S(P) = S(Q)+T
 */
int findTargetSumWays(vector<int>& nums, int S) {
    long sum = 0;
    for(int num : nums) sum += num;
    if((S+sum)%2 == 1 || S > sum) return 0;
    S = (S+sum)/2;
    int *dp = new int[S+1];
    memset(dp, 0, (S+1)*sizeof(int));
    dp[0] = 1;
    for(int num : nums) {
        for(int j = S; j >= num; j--) 
            dp[j] += dp[j-num];
    }
    int ans = dp[S];
    delete[] dp;
    return ans;
}

/** leetcode-32 最长有效括号
 *  input: "(()" -> output: 2
 *  input: ")()())" -> output: 4
 */
int longestValidParentheses(string s) {
    int maxans = 0;
    vector<int> dp(s.size(), 0);
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == ')') {
            if(s[i-1] = '(')
                dp[i] = (i >= 2 ? dp[i-2] : 0)+2;
            else if(i - dp[i-1]> 0 && s[i-dp[i-1]-1] == '(')
                dp[i] = dp[i-1] + ((i-dp[i-1]) >= 2 ? dp[i-dp[i-1]-2] : 0) + 2;
            maxans = max(maxans, dp[i]);
        }
    }
    return maxans;
}


/** leetcode-714 买卖股票的最佳时机含手续费
 *  @param: prices=[1,3,2,8,4,9], fee=2
 *  @return: 8  ((8-1)-2)+((9-4)-2)=8
 */
int maxProfit3(vector<int>& prices, int fee) {
    int cash = 0, hold = -prices[0];
    for(int i = 1; i < prices.size(); i++) {
        cash = max(cash, hold+prices[i]-fee);
        hold = max(hold, cash-prices[i]);
    }

    return cash;
}

/** leetcode-139 单词拆分
 *  @param: s="leetcode", wordDict=["leet", "code"]
 *  @return: true
 */
bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size()+1, false);
    unordered_set<string> m(wordDict.begin(), wordDict.end());
    dp[0] = true;
    int maxl = 0;
    for(string word : wordDict)
        maxl = max(maxl, (int)word.size());
    for(int i=1; i <= s.size(); i++) {
        for(int j=max(i-maxl,0); j < i; j++) {
            if(dp[j] && m.find(s.substr(j, i-j)) != m.end()) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.size()];
}

/** leetcode-5 最长回文子串
 *  @param: a string 
 *  @return: the longest palindrome substring of input string
 */
string longestPalindrome(string s) {
    if(s.size() < 2) return s;
    int len = s.size();
    vector<vector<int>> dp (len, vector<int>(len, 0));
    for(int i = 0; i < len; i++) 
        dp[i][i] = 1;
    int maxlen = 1, start = 0;
    for(int j = 1; j < len; j++) {
        for(int i = 0; i < j; i++) {
            dp[i][j] = s[i] == s[j] && (j-i < 3 || dp[i+1][j-1]);

            if(dp[i][j]) {
                int curlen = j-i+1;
                maxlen = max(curlen, maxlen);
                start = i;
            }
        }
    }
    return s.substr(start, start+maxlen);
}

/** leetcode-152 乘积最大子数组
 *  @param: [2, 3, -2, 4]
 *  @return: 6    子数组[2, 3]有最大乘积 6
 */
int maxProduct(vector<int>& nums) {
    int ans = 0, imax = 1, imin = 1;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] < 0) swap(imin, imax);
        imax = max(imax*nums[i], nums[i]);
        imin = min(imin*nums[i], nums[i]);
        ans = max(imin, imax);
    }
    return imax;
}

/** leetcode-221 最大正方形
 *  @param: a 2-D binary matrix
 *  @return: the max Square only contains 1's
 */
int maximalSquare(vector<vector<char>>& matrix) {
    int rows = matrix.size(), cols = rows > 0 ? matrix[0].size() : 0;
    vector<vector<int>> dp(rows+1, vector<int>(cols+1, 0));
    int maxsqlen = 0;
    for(int i = 1; i <= rows; i++) {
        for(int j = 1; j <= cols; j++) {
            if(matrix[i-1][j-1] == '1') {
                dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
                maxsqlen = max(maxsqlen, dp[i][j]);
            }
        }
    }
    return maxsqlen*maxsqlen;
}

/** leetcode-983 最低票价
 *  @param: days=[1,4,6,7,8,20], 
 *  @param: costs=[2,7,15], costs[0]-one day; costs[1]-7 days; costs[2]-30 days
 *  @return: minimum costs
 */
int mincostTickets(vector<int>& days, vector<int>& costs) {

}

int main(){
    vector<int> prices={1, 3, 2, 8, 4, 9};
    int fee = 2;
    cout << maxProfit3(prices, fee) << endl;
    return 0;
}
