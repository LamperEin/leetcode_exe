#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int slidingPuzzle(vector<vector<char>>& board) {
    int ans;
    return ans;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int ans = 0;
    for (int i = 0; i != grid.size(); ++i)
        for (int j = 0; j != grid[0].size(); ++j) {
            int cur = 0;
            queue<int> queuei;
            queue<int> queuej;
            queuei.push(i);
            queuej.push(j);
            while (!queuei.empty()) {
                int cur_i = queuei.front(), cur_j = queuej.front();
                queuei.pop();
                queuej.pop();
                if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != 1)
                    continue;
                ++cur;
                grid[cur_i][cur_j] = 0;
                int di[4] = {0, 0, 1, -1};
                int dj[4] = {1, -1, 0, 0};
                for (int index = 0; index != 4; ++index) {
                    int next_i = cur_i + di[index], next_j = cur_j + dj[index];
                    queuei.push(next_i);
                    queuej.push(next_j);
                }
            }
            ans = max(ans, cur);
        }
    return ans;
}

int main() {

    return 0;
}