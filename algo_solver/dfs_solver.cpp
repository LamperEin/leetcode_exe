#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void dfs(vector<vector<char>>& grid, int x, int y, int x_len, int y_len, int dx[], int dy[]) {
    //int cnt = 1;
    grid[x][y] = '0';
    for(int i = 0; i < 4; i++) {
        int tx = x+dx[i], ty = y+dy[i];
        if(tx >= 0 && ty >= 0 && tx < x_len && ty < y_len && grid[tx][ty]=='1')
            dfs(grid, tx, ty, x_len, y_len, dx, dy);
    }
    return;
}

int numIsLands(vector<vector<char>>& grid) {
    int x_len, y_len;
    int count = 0;
    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};
    x_len = grid.size(), y_len = grid[0].size();
    for(int i = 0; i < x_len; i++) {
        for(int j = 0; j < y_len; j++) {
            if(grid[i][j] == '1') {
                dfs(grid, i, j, x_len, y_len, dx, dy);
                count++;
            }
        }
    }
    return count;
}

void dfs(vector<vector<int>>& grid, int x, int y, int x_len, int y_len, int dx[], int dy[], int& cnt) {
    cnt += 1;
    grid[x][y] = 0;
    for(int i = 0; i < 4; i++) {
        int tx = x+dx[i], ty = y+dy[i];
        if(tx >= 0 && ty >= 0 && tx < x_len && ty < y_len && grid[tx][ty]==1)
            dfs(grid, tx, ty, x_len, y_len, dx, dy, cnt);
    }
    return ;
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int ans = 0;
    int x_len = grid.size(), y_len = grid[0].size();
    if(x_len == 0) return 0;
    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};
    for(int i = 0; i < x_len; ++i) {
        for(int j = 0; j < y_len; ++j) {
            if(grid[i][j] == 1) {
                int cnt = 0;
                dfs(grid, i, j, x_len, y_len, dx, dy, cnt);
                if(cnt > ans)
                    ans = cnt;
            }
        }
    }

    return ans;
}

int dfs(int i, int j, int m, int n, int k, vector<vector<bool>> visited) {
    if(i<0 || i>=m || j<0 || j>=n || visited[i][j] || i/10+i%10+j/10+j%10>k)
        return 0;
    visited[i][j] = true;
    return dfs(i+1, j, m, n, k, visited) + 
           dfs(i-1, j, m, n, k, visited) +
           dfs(i, j-1, m, n, k, visited) +
           dfs(i, j+1, m, n, k, visited) + 1;
}

int movingCount(int m, int n, int k) {
    vector<vector<bool>> visited(m, vector<bool>(n, 0));
    return dfs(0, 0, m, n, k, visited);
}

// the head function for findTargetSumWays
int dfs(vector<int>& nums, int S, int left) {
    if (S == 0 && left == nums.size()) return 1;
    if (left >= nums.size()) return 0;
    int ans = 0;
    ans += dfs(nums, S - nums[left], left + 1);
    ans += dfs(nums, S + nums[left], left + 1);
    return ans;
}

/** leetcode-494 目标和
 *  input: [1, 1, 1, 1, 1], s: 3 -> output: 5
 *  -1+1+1+1+1 = 3, +1-1+1+1+1 = 3, +1+1-1+1+1 = 3,
 *  +1+1+1-1+1 = 3, +1+1+1+1-1 = 3
 */
int findTargetSumWays(vector<int>& nums, int S) {
    int ans = 0;
    return dfs(nums, S, 0);
}

/** leetcode-542 01矩阵
 *  input: 0 0 0  -> output: 0 0 0
 *         0 1 0             0 1 0
 *         1 1 1             1 2 1
 */
vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    
}

// the help function for maxPathSum
int maxPathSumCore(TreeNode* root, int& ans) {
    if(root == NULL) return 0;
    int leftt = max(maxPathSumCore(root->left, ans), 0);
    int rightt = max(maxPathSumCore(root->right, ans), 0);
    // the price to start a new path where `node` is a highest node
    int subtree = root->val + leftt + rightt;
    ans = max(ans, subtree);
    return root->val+max(leftt, rightt);
}

/** leetcode-124 二叉树中的最大路径和
 *  @param: hte root node of  tree
 *  @return: the max path sum of tree
 */
int maxPathSum(TreeNode* root) {
    int val = INT_MIN;
    maxPathSumCore(root, val);
    return val;
}

int main() {
    vector<int> nums = {1, 1, 1, 1, 1};
    cout << findTargetSumWays(nums, 3) << endl;
    return 0;
}