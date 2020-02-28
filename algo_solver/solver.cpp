#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    vector<int> a;
    for (int i = 0; i < numRows; i++) {
        a.clear();
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) a.push_back(1);
            //else if (j+1 == i) a.push_back(1);
            else a.push_back(res[i-1][j-1]+res[i-1][j]);
        }
        res.push_back(a);
    }
    
    return res;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    int left, right, down, up;
    int row = matrix.size(), col = matrix[0].size();
    while(res.size() == row * col) {
        //push num in res if in the bound,turn down if touch the bound
        // 
    }
   
}

vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    if(matrix.empty()) return res;
    int row = matrix.size(), col = matrix[0].size(), r = 0, c = 0, up=1;
    while(res.size() < row*col) {
        if(up) {
            while(r >= 0 && c <= (col-1))
                res.push_back(matrix[r--][c++]);
            //将下标移动到转向之后的开始位置
            if(c > col - 1) {
                c = col -1;
                r += 2;
            } else if(r < 0) r=0;
            up = 0;
        } else {
            while (r <= row - 1 && c >= 0)
                res.push_back(matrix[r++][c--]);
            if(r > row - 1) {
                c += 2;
                r = row - 1;
            } else if(c < 0) c = 0; 
            up = 1;
        }
    }
    return res;
}

vector<int> plusOne(vector<int>& digits) {
    int carry = 0, len = digits.size();
    vector<int>::iterator it = digits.begin();
    if (digits[len-1] != 9) {
        digits[len-1] += 1;
    } else {
        digits[len-1] = 0;
        carry = 1;
        for (int i = len-2; i >= 0; i--) {
            if (digits[i] + carry == 10)
                digits[i] = 0;
            else { 
                digits[i] += carry;
                carry = 0;
            }  
            if (carry == 0)
                break;
        }
        if (carry == 1) {
           // if (digits[0] != 9);
           digits[0] = 0;
            digits.insert(it, 1);
        }
    }
    return digits;   

}

int dominantIndex(vector<int>& nums) {
    //bool flag = true;
    int max_idx = max_element(nums.begin(), nums.end()) - nums.begin();
    for (int i = 0; i < nums.size(); i++) {
        if (2*nums[i] > nums[max_idx] )
            //flag = false;
            return -1;
    }
    return max_idx;
}

int pivotIndex(vector<int>& nums) {
    if (nums.size() != 0){
        int sum = 0, left = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        for (int j = 0; j < nums.size(); j++) {
            if (left * 2 + nums[j] == sum)
                return j;
            sum -= nums[j]; 
            left += nums[j];           
        }
    }
    return -1;
    
}

int main() {
    int numRows = 5;
    vector<vector<int>> res; 
    res = generate(numRows);
    for (int i = 0; i < numRows; i++)
    {
        for (auto const element:res[i])
        {
            cout << element << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    return 0;
}