#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;

/* input: HG[3|B[2|CA]]F
** HG[3|B[2|CA]]F -> HG[3|BCACA]F -> HGBCACABCACABCACAF
** ouput: HGBCACABCACABCACAF
*/
string stringUnzip(string s) {
    int i = 0;
    while(i < s.length()){
        if(s[i] == ']'){
            int j = i;//j用来向前寻找与]相匹配的[
            int k = 0;//k用来记录'|'所在位置
            while(s[j] != '['){
                if(s[j] == '|')
                    k = j;
                j--;
            }
            int len = stoi(s.substr(j+1,k-j));
            string s1 = s.substr(k+1,i - k - 1);
            string s2;
            for(int si = 0; si < len; si++){//将识别到的括号内容进行解码
                s2 += s1;
            }
            s = s.replace(j,i-j+1,s2);
            i = j;//替换后i所指向的内容变化，从替换部分的头开始再寻找
        }
        i++;
    }
    return s;
}
/*
**
*/
vector<int> numOfbuildingsInsight(int x[], int n) {
    vector<int> a, b;
    stack<int> st1, st2;

    for(int i = 0, j = n; i < n, j >= 0; i++, j--) {
        a.push_back(st1.size());
        b.push_back(st2.size());

        while(!st1.empty() && st1.top() <= x[i]) st1.pop();
        while(!st2.empty() && st2.top() <= x[j]) st2.pop();
        st1.push(x[i]);
        st2.push(x[j]);
    }
    reverse(b.begin(), b.end());
    for(int i = 0; i < n; i++)
        b[i] = b[i] + a[i] + 1;
    return b;
}

/*
**
*/
int rest(vector<int> work, vector<int> slp, int n) {
    vector<vector<int>> dp(3, vector<int>(n+1));
    dp[0][0] = 0, dp[1][0] = 0, dp[2][0] = 0;
    for(int i = 1; i <=n; i++) {
        dp[0][i] = max(dp[0][i-1], max(dp[i][i-1], dp[2][i-1])); // rest
        if(slp[i-1])
            dp[1][i] = max(dp[2][i-1], dp[0][i-1]) + 1; // fitting
        if(work[i-1])
            dp[2][i] = max(dp[1][i-1], dp[0][i-1]) + 1; // working
    }
    return n - max(dp[0][n], max(dp[1][n], dp[2][n]));
}

/*
**
*/
int numOfEyes(int L, int n, vector<vector<int>>& eyes){
    int ans = 0;
    int pre = 0, i = 0, last = 0;
    sort(eyes.begin(), eyes.end(), [](vector<int>& a, vector<int>& b) {
        return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    });
    
    while(i < eyes.size()) {
        while(i < eyes.size() && eyes[i][0] <= pre) {
            last = max(last, eyes[i][1]);
            i++;
        }
        ++ans;
        pre = last;
        if(i < eyes.size() && eyes[i][0] > pre) {
            ans = -1;
            break;
        }
        if(last >= L) break;
    }
    
    return ans == -1 || last < L? -1 : ans;

}


int main() {
    string s = "HG[3|B[2|CA]]F";
    cout << stringUnzip(s) << endl;
    return 0;
}