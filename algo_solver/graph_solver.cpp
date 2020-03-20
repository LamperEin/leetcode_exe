#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxdist = 9999;

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

int main() {
    
    
    return 0;
}