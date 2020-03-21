#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <queue>
#include <cstring>
#include <bitset>

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

int fib(int n) {
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    int a = 0, b = 1, i = 1;
    while(i < n) {
        i++;
        int tmp = b;
        b = a+b;
        a = tmp;
        if(b>1e9+7)
            b = b % (1000000007);
    }
    return b;

}

vector<int> distributeCandies(int candies, int num_people) {
    vector<int> res;
    int candy = 1, i = 0;
    for(int j = 0; j < num_people; j++) 
        res.push_back(0);
    while(candies > 0 && (candies - candy) >= 0) {
        candies -= candy;
        res[i%num_people] += candy;
        candy++;i++; 
    }
    candy = candies;
    res[i%num_people] += candy;
    return res;
}

vector<vector<int>> findContinuousSequence(int target) {
    vector<vector<int>> res;
    int i = 1;
    while(target > 0) {
        target -= i++;
        if(target > 0 && target % i == 0) {
            vector<int> tmp;
            for(int j = 0; j < i; j++)
                tmp.push_back(target / i + j);
            res.push_back(tmp);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int minArray(vector<int>& numbers) {
    
}

bool canThreePartsEqualSum(vector<int>& A) {    
    int s = accumulate(A.begin(), A.end(), 0);
    if(s % 3 != 0) return false;
    int target = s / 3;
    int n = A.size(), i = 0, cur = 0;
    while(i < n) {
        cur += A[i];
        if(cur == target)
            break;
        ++i;
    }
    if(cur != target)
        return false;
    int j = i+1;
    while(j + 1 < n) {
        cur += A[j];
        if(cur == target*2)
            return true;
        ++j;
    }
    return false;
}

bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    return !(rec1[2] <= rec2[0] ||  // left
             rec1[3] <= rec2[1] ||  // bottom
             rec1[0] >= rec2[2] ||  // right
             rec1[1] >= rec2[3]);   // top
}

vector<int> constructArr(vector<int>& a) {
    int len = a.size();
    vector<int> b(len);
    int tmp = 1;
    for(int i = 0; i < len; i++) {
        b[i] = tmp;
        tmp *= a[i];
    }
    tmp = 1;
    for(int i = len-1; i >= 0; i--) {
        b[i] *= tmp;
        tmp *= a[i];
    }
    return b;
}

bool isStraight(vector<int>& nums) {
    if(nums.size() < 1) return false;
    int cnt_zero = 0;
    int cnt_gap = 0;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] = 0) ++cnt_zero;
    }

    int small = cnt_zero;
    int big = small+1;
    while(big < nums.size()) {
        
        if(nums[big] == nums[small]) return false;

        cnt_gap += nums[big] - nums[small] - 1;
        small = big;
        ++big;
    }
    return cnt_gap >= cnt_zero? true : false;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    deque<int> idx;
    int len = nums.size();
    if(len == 0) return ans;
    for(int i = 0; i < len; i++) {
        while(!idx.empty() && i - idx.front() + 1 > k)
            idx.pop_front();
        while(!idx.empty() && nums[idx.back()] < nums[i])
            idx.pop_back();
        idx.push_back(i);
        if(i >= k-1)
            ans.push_back(nums[idx.front()]);
    }
    return ans;
}

int singleNumber(vector<int>& nums) {
    // method-1: use unordered_map 
    // method-2
    vector<int> v(32, 0);
    for(int i = 0; i < nums.size(); i++) {
        bitset<32> t(nums[i]);
        for(int j = 0; j < t.size(); j++) {
            if(t[j] == 1) v[j]++;
        }
    }
    bitset<32> t;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] % 3 != 0)
            t.set(i);
    }
    return (int)t.to_ulong();
}

vector<int> singleNumbers(vector<int>& nums) {
    vector<int> ans(2, 0);
    int diff = 0;
    for(int num : nums) diff ^= num;
    diff = diff & (-diff);
    for(int num : nums) {
        if((diff & num) == 0)
            ans[0] ^= num;
        else
            ans[1] ^= num;
    }
    return ans;
}


int main() {
    int target = 15;
    vector<vector<int>> res;
    res = findContinuousSequence(target);
    cout << "[";
    for (int i = 0; i < res.size(); i++) {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << "],";
    }
    cout << "]" << endl;
    //cout << endl;
    
    return 0;
}