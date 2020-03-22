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


int main() {
    vector<vector<int>> grid1 = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                 {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                 {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                 {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                 {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                 {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                 {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    vector<vector<int>> grid2 = {{0,0,0,0,0,0,0,0}};
    cout << maxAreaOfIsland(grid1) << endl;
    cout << maxAreaOfIsland(grid2) << endl;
    return 0;
}