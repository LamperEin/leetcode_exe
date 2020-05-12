#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <cctype>

using namespace std;
/**board = [ ['A', 'B', 'C', 'E'], 
 *           ['S', 'F', 'C', 'S'], 
 *           ['A', 'D', 'E', 'E']]
 * 
 *  for word = "ABCCED" -> true
 *  for word = "SEE" -> true
 *  for word = "ABCB" -> false
 */
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
        }
    }
}

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
        subsetsCore(nums, i+1, ans, tmp);
        tmp.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> tmp;
    subsetsCore(nums, 0, ans, tmp);
    return ans;
}

// the help function for letterCombinations
void backtracking(unordered_map<char, string>& table, vector<string>& ans, 
                  string& tmp, string& digits, int idx) {
    if(idx == digits.size()) {
        ans.push_back(tmp);
        return;
    }
    
    for(char c : table[digits[idx]]) {
        tmp += c;
        backtracking(table, ans, tmp, digits, idx+1);
        tmp.pop_back();
    }
}
/*leetcode-17 电话号码的字母组合
* input: "23"
* output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
*/
vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if(digits.size() == 0) return ans;
    unordered_map<char, string> table {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, 
                                         {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, 
                                         {'8', "tuv"}, {'9', "wxyz"}};
    string tmp = "";
    backtracking(table, ans, tmp, digits, 0);
    return ans;
}

// the help function for generateParanthesis
bool isLegal(string s, int n) {
    stack<char> sk;
    for(char c : s) {
        if(c == '(')
            sk.push(c);
        else if(!sk.empty() && c == ')')
            sk.pop();
        else return false;
    }
    return 2*n-s.size() >= sk.size() ? true : false;
}

void backtracking(vector<string>& ans, string& tmp, int n, int idx) {
    if(idx == 2*n) {
        ans.push_back(tmp);
        return;
    }
    for(char c : "()") {
        tmp += c;
        if(isLegal(tmp, n)) {
            backtracking(ans, tmp, n, idx+1);
        }
        tmp.pop_back();
    }
}

/* leetcode-22 括号生成
*  input: n = 3
*  output: ["((()))", "(()())", "(())()", 
*           "()(())", "()()()"]
*/
vector<string> generateParanthesis(int n) {
    vector<string> ans;
    if(n == 0) return ans;
    string tmp = "(";
    backtracking(ans, tmp, n, 1);
    return ans;
}

/** leetcode-36 有效的数独
 *  @param：board 数独棋盘
 *  @return: is a valid Sudoku
 */
bool isValidSudoku(vector<vector<char>>& board) {
	unordered_map<char, int>row[9], column[9], sub[9];
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if(board[i][j] != '.' && 
				(row[i][board[i][j]]++ ||
				column[j][board[i][j]]++ || 
				sub[i / 3 * 3 + j / 3][board[i][j]]++))
				return false;
	return true;
}

// the help function for solveSudoku
void solveSudokuCore(vector<vector<char>>& board, int x, int y) {
    if(x == 8 && y == 8) return;
    if(board[x][y] =='.') solveSudokuCore(board, x, y+1);
}
/** leetcode-37 解数独
 *  @param: board 数独棋盘
 *  @return: 数独棋盘的一个解
 */
void solveSudoku(vector<vector<char>>& board) {
    solveSudokuCore(board, 0, 0);
}

// the help function for combinationSum
void combinationSumCore(vector<int>& candidates, int target, vector<int>& tmp, vector<vector<int>>& ans, int left) {
    if(target == 0) {
        ans.push_back(tmp);
        return;
    }
    for(int i = left; i < candidates.size(); i++) {
        if(target-candidates[i] >= 0) {
            tmp.push_back(candidates[i]);
            combinationSumCore(candidates, target-candidates[i], tmp, ans, i);
            tmp.pop_back();
        }
    }
}

/** leetcode-39 组合总和
 *  @param: candidates=[2,3,6,7], target=7
 *  @return: [[7], [2, 2, 3]]
 */
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    if(candidates.size() == 0) return ans;
    vector<int> tmp;
    combinationSumCore(candidates, target, tmp, ans, 0);
    return ans;
}

// the help function for partition
void backtracking(string& s, vector<string>& tmp, vector<vector<string>>& ans) {
    
}

/** leetcode-131 分割回文串
 *  @param: a string "aab"
 *  @return: all string that is a palindrome
 */
vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> tmp;
    backtracking(s, tmp, ans);
    return ans;
}

// the help function for letterCasePermutation
void backtracking(string& S, string& tmp, int left, vector<string>& ans) {
    if(left == S.size()) {
        ans.push_back(tmp);
        return;
    }
    if(isdigit(S[left])) {
        tmp += S[left];
        backtracking(S, tmp, left+1, ans);
    } else {
        tmp += tolower(S[left]);
        backtracking(S, tmp, left+1, ans);
        tmp = tmp.substr(0, left);
        tmp +=toupper(S[left]);
        backtracking(S, tmp, left+1, ans);
    }
}

/** leetcode-784 字母大小写排列
 *  @param: S="a1b2"
 *  @return: ["a1b2", "a1B2", "A1b2", "A1B2"]
 */
vector<string> letterCasePermutation(string S) {
    vector<string> ans;
    string tmp = "";
    backtracking(S, tmp, 0, ans);
    return ans;
}

int main() {
    string s = "a1b2";
    vector<string> ans = letterCasePermutation(s);
    for(string str1 : ans)
        cout << str1 << " ";
    cout << endl;
    return 0;
}