#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <queue>
#include <cstring>
#include <bitset>
#include <cmath>
using namespace std;

vector<int> res;
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
    if(numbers.size() == 0) return 0;
    int l = 0, r = numbers.size()-1;
    while(l < r) {
        int mid = l + (r-l)>>1;
        if(numbers[mid] > numbers[r])
            l = mid + 1;
        else if(numbers[mid] == numbers[r])
            r--;
        else r = mid;
    }
    return numbers[l];
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

int missingNumber(vector<int>& nums) {
    int left = 0, right = nums.size();
    while(left < right) {
        int mid = (left + right)>>2;
        if(nums[mid] != mid) {
            right = mid;
        } 
        else left = mid+1;

    }
    return left;
}

int search(vector<int>& nums, int target) {
    int i = 0, j = nums.size()-1;
    while(i <= j) {
        int mid = i + (j-i)/2;
        if(nums[mid] <= target)
            i = mid + 1;
        else j = mid-1;
    }
    int right = i;
    i = 0, j = nums.size()-1;
    while(i <= j) {
        int mid = i + (j - i)/2;
        if(nums[mid] >= target)
            j = mid - 1;
        else i = mid+1;
    }
    int left = j;
    return right - left - 1;
}

// use merge sort to solve reverse pairs
int reversePairsCore(vector<int>& nums, int l, int r) {
    if(r-l<=1) return 0;
    int mid = (r+l)>>1;
    vector<int> tmp;
    int ans = reversePairsCore(nums, l, mid) + reversePairsCore(nums, mid, r);

    int i = l;
    int j = mid;
    while(i < mid && j < r) {
        if(nums[i] > nums[j]) {
            ans += mid - i;
            tmp.push_back(nums[j++]);
        } else {
            tmp.push_back(nums[i++]);
        }
    }
    while(i < mid) tmp.push_back(nums[i++]);
    while(j < r) tmp.push_back(nums[j++]);
    copy(tmp.begin(), tmp.end(), nums.begin()+l);
    return ans;
}

int reversePairs(vector<int>& nums) {
    return reversePairsCore(nums, 0, nums.size());
}

int nthUglyNumber(int n) {
    if(n <= 0) return 0;
    vector<int> ugly(n ,0);
    ugly[0] = 1;
    int p2 = 0, p3 = 0, p5 = 0;
    for(int i = 1; i < n; i++) {
        ugly[i] = min(ugly[p2]*2, min(ugly[p3]*3, ugly[p5]*5));
        if(ugly[i] == ugly[p2]*2) p2++;
        if(ugly[i] == ugly[p3]*3) p3++;
        if(ugly[i] == ugly[p5]*5) p5++;
    }
    return ugly[n-1];
}

int findNthDigit(int n) {
    n -= 1;
    for(long digits = 1; digits < 11; digits++) {
        int first_num = pow(10, digits-1);
        if(n < 9*first_num*digits )
            return int(to_string(first_num + n/digits)[n%digits])-'0';
        n -= 9*first_num*digits;
    }
    return 0;
}

int countDigitOne(int n) {
    int count = 0;
    long i = 1; //指向遍历的位数，i=1即个位，i=10即十位
    while(n/i!=0) {

        long high = n/(10*i);
        long cur = (n/i)%10;
        long low = n-(n/i)*i;
        if(cur == 0)
            count += high*i;
        else if (cur == 1)
            count += high * i + low + 1;
        else
            count += high*i+i;
        i *= 10;
    }
    return count;
}

vector<int> getLeastNumbers(vector<int>& nums, int k) {
    vector<int> ans(k, 0);
    if(k == 0) return ans;
    priority_queue<int> q;
    for(int i = 0; i < k; i++) q.push(nums[i]);
    for(int i = k; i < nums.size(); i++) {
        if(q.top() > nums[i]) {
            q.pop();
            q.push(nums[i]);
        }
    }
    for(int i = 0; i < k; i++) {
        ans[i] = q.top();
        q.pop();
    }
    return ans;
}

int majorityElement(vector<int>& nums) {
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(cnt = 0) {
            cnt = 1;
            ans = nums[i];
        } else if (ans == nums[i]) {
            cnt++;
        } else cnt--;
    }
    return ans;
}
// 剑指offer 面试题17
void saveNum(string number) {

}

void permutionNum(string& number, int length, int idx) {
    if(idx == length) {
        saveNum(number);
        return;
    } else {
        for(int i = 0; i < 10; i++) {
            number[idx] = '0'+i;
            permutionNum(number, length, idx+1);
        }
    }
}

vector<int> printNumbers(int n) {
    if(n <= 0) return res;
    string number(n, 0);
    for(int i = 0; i <= 9; i++) {
        number[0] = i+'0';
        permutionNum(number, n, 1);
    }
    return res;
}

void rotate(vector<vector<int>>& matrix) {

}

/** leetcode 颜色分类
 *  input: [2, 0, 2, 1, 1, 0] -> output: [0, 0, 1, 1, 2, 2]
 */
void sortColors(vector<int>& nums) {
    if(nums.size() < 2) return;
    int n = nums.size();
    vector<int> cnt(3, 0);
    for(int i = 0; i < n; i++) 
        cnt[nums[i]]++;

    int idx = 0;
    for(int i = 0; i < 3; i++) {
        while(cnt[i] > 0) {
            nums[idx++] = i;
            cnt[i]--;
        }
    }
}
// the help function for rotate
void reverse(vector<int>& nums, int l, int r) {
    while(l < r) 
        swap(nums[l++], nums[r--]);
}
/** leetcode-189 旋转数组
 *  input: [1, 2, 3, 4, 5, 6, 7] , k = 3
 *  output: [5, 6, 7, 1, 2, 3, 4]
 */
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;
    reverse(nums, 0, n-1);
    reverse(nums, 0, k-1);
    reverse(nums, k, n-1);
}

/** leetcode-119 杨辉三角
 *  input: 3 -> output: [1, 3, 3, 1]
 */
vector<int> getRow(int rowIndex) {
    vector<int> ans(rowIndex+1);
    for(int i = 0; i <= rowIndex; i++) {
        for(int j = i; j >= 0; j--) {
            if(j == 0 || j == i)
                ans[j] = 1;
            else ans[j] = ans[j] + ans[j-1];
        }
    }
    return ans;
}

/** leetcode 移除元素
 *  input: [3, 2, 2, 3], val=3
 *  output: [2, 2], 2;
 */
int removeElement(vector<int>& nums, int val) {
    int k = 0;
    for(int i = 0; i < nums.size(); i++)
        if(nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    return k;
}

/** leetcode-209 长度最小的子数组
 *  input: s=7, nums=[2, 3, 1, 2, 4, 3]
 *  output: 2
 *  子数组[4, 3]是该条件下的长度最小的连续子数组
 */
int minSubArray(int s, vector<int>& nums) {
    
}

int main() {
    vector<int> nums = getRow(3);
    for(int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
    return 0;
}


