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



int main() {


}