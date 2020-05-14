#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>
#include <string>

using namespace std;

bool backtrack(vector<vector<char>>& board, int r, int c, string word, int idx) {
    if(idx == word.size()) return true;
    if(r < 0 || r >= board.size() || 
       c < 0 || c >= board[0].size()) return false;
    if(board[r][c] != word[idx]) return false;

    board[r][c] = '*';
    if(backtrack(board, r-1, c, word, idx+1)||
       backtrack(board, r+1, c, word, idx+1)||
       backtrack(board, r, c-1, word, idx+1)||
       backtrack(board, r, c+1, word, idx+1))
       return true;
    board[r][c] = word[idx];
    return false;
}

bool exit(vector<vector<char>>& board, string word) {
    if(board.empty() || board[0].empty()) return word.empty();
    for(int r = 0; r < board.size(); r++) {
        for(int c = 0; c < board[0].size(); c++) {
            if(backtrack(board, r, c, word, 0))
                return true;
        }
    }
    return false;
}

<<<<<<< HEAD
bool isDupliacte(string& s, int start, int end) {
    for(int i = start; i < end; i++) {
        if(s[i] == s[end]) return true;
    }
    return false;
}

void backtrack(string& s, int pos, vector<string>& ans) {
    if(pos >= s.size()) {
        ans.push_back(s);
        return;
    } else {
        for(int i = pos; i < s.size(); i++) {
            if(isDupliacte(s, pos, i)) continue;
            swap(s[pos], s[i]);
            backtrack(s, pos+1, ans);
            swap(s[pos], s[i]);
=======
void backtrack(vector<vector<string>>& ans, vector<int>& solu, int ith, int n) {
    if(ith == n) {
        string blank = "";
        for(int i = 0; i < n; i++) blank +='.';
        vector<string> tmp(n, blank);
        for(int i = 0; i < n; i++)
            tmp[i][solu[i]] = 'Q';
        ans.push_back(tmp);
        return;
    }
    for(int i = 0; i < n; ++i) {
        bool legal = true;
        for(int j = 0; j < ith; ++j) {
            if(solu[j]==i || solu[j]== i-j+ith || solu[j]== j-ith+i)
                legal = false;
        }
        if(legal) {
            solu[ith] = i;
            backtrack(ans, solu, ith+1, n);
>>>>>>> 84f23360f2eec80ea5f507a0bcbbca3e56f61ca6
        }
    }
}

<<<<<<< HEAD
vector<string> permutation(string s) {
    vector<string> ans;
    backtrack(s, 0, ans);
    return ans;
}

=======
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<int> solu(n, -1);
    backtrack(ans, solu, 0, n);
    return ans;
}

void permutationCore(string s, int left, vector<string>& ans) {
    if(left = s.size()) {
        ans.push_back(s);
        return;
    }
    for(int i = left; i < s.size(); i++) {
        swap(s[i], s[left]);
        permutationCore(s, left+1, ans);
        swap(s[i], s[left]);
    }
}

vector<string> permutation(string S) {
    vector<string> ans;
    permutationCore(S, 0, ans);
    return ans;
}

void permuteUniqueCore(vector<int> nums, int left, vector<vector<int>>& ans) {
    if(left == nums.size()) {
        ans.push_back(nums);
        return;
    }
    for(int i = left; i < nums.size(); i++) {
        if(i != left && nums[i] == nums[left]) continue;
        swap(nums[left], nums[i]);
        permuteUniqueCore(nums, left+1, ans);
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    permuteUniqueCore(nums, 0, ans);
    return ans;
}

void combineCore(int n, vector<int>& tmp, int left, int k, vector<vector<int>>& ans) {
    if(k == 0) {
        ans.push_back(tmp);
        return;
    }
    for(int i = left; i <= n; i++) {
        tmp.push_back(i);
        combineCore(n, tmp, i+1, k-1, ans);
        tmp.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> nums;
    combineCore(n, nums, 1, k, ans);
    return ans;
}

void subsetsCore(vector<int>& nums, int start, vector<vector<int>>& ans, vector<int>& tmp) {
    ans.push_back(nums);
    for(int i = start; i < nums.size(); i++) {
        tmp.push_back(nums[i]);
        subsetsCore(nums, start+1, ans, tmp);
        tmp.pop_back();
    }
}
>>>>>>> 84f23360f2eec80ea5f507a0bcbbca3e56f61ca6

int main() {
    int n = 4;

<<<<<<< HEAD
    cout << (n&(n-1)) << endl;
    return 0;
}   
=======
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> tmp;
    subsetsCore(nums, 0, ans, tmp);
    return ans;
}

vector<string> letterCombinations(string digits) {
    
}



int main() {
   const int n = 4;
    vector<vector<int>> ans = combine(4, 2);
    for(int i = 0; i < ans.size(); ++i) {
        for(int j = 0; j < 2; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    //cout << cnt << endl;
    return 0;
}
>>>>>>> 84f23360f2eec80ea5f507a0bcbbca3e56f61ca6
