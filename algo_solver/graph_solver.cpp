#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxdist = 9999;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

void Dijkstra(int n, int v, vector<int>& dist, vector<int>& &pre, vector<vector<int>>& d) {
    vector<bool> s(n+1);
    for(int i = 1; i <= n; i++) { // 初始化出发点到其他个点的距离dis[]以及各点的前一个访问点pre[]
        dist[i] = d[v][i];
        if(dist[i] < maxdist)
            pre[i] = v;
        else
            pre[i] = 0;
    }
    dist[v] = 0;
    s[v] = true;
    for(int i = 2; i <= n; i++) { // 总的迭代次数
        int best = v;
        int tmp = maxdist;
        for(int j = 1; j <= n; j++) { // 找到最小距离
            if(!s[j] && dist[j] < tmp) {
                tmp = dist[j];
                best = j;
            }
        }
        s[best] = true;
        for(int j = 1; j <= n; j++) { // 更新dist和pre
            if(!s[j] && d[best][j] != maxdist) {
                int newdist = dist[best] + d[best][j];
                if(newdist < dist[j]) {
                    dist[j] = newdist;
                    pre[j] = best;
                }
            }
        }
    }
}

/** 
 * 
 * 
 */

Node* cloneGraph(Node* node) {
    Node* ans;
    return ans;
}

/** leetcode-207 课程表
 *  @param: number of courses
 *  @param: the prerequisites courses
 *  @return: the possiblity of finish the courses
 */
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    map<int, set<int>> adjcent;
    vector<int> indegree(numCourses);
    for(auto& edge : prerequisites) {
        int a = edge[0];
        int b = edge[1];
        adjcent[b].insert(a);
        ++indegree[a];
    }
    int cnt = 0;
    queue<int> q;
    for(int i = 0; i < numCourses; ++i) {
        if (!indegree[i]) q.push(i);
    }
    while(!q.empty()) {
        auto v = q.front();
        q.pop();
        ++cnt;
        auto& adjs = adjcent[v];
        for(auto adj : adjs) {
            --indegree[adj];
            if(!indegree[adj]) q.push(adj);
        }
    }
    return cnt == numCourses;
}

int main() {
    
    
    return 0;
}