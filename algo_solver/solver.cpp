#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <queue>
#include <cstring>
#include <bitset>
#include <cmath>
#include <stack>
#include <map>

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
    if(matrix.empty()) return res;
    int left=0, right=matrix[0].size()-1, down=matrix.size(), up=0;

    while(1) {

        for(int i=left; i <= right; i++) res.push_back(matrix[up][i]); // go right

        if(++up > down) break;
        for(int i = up; i <= down; i++) res.push_back(matrix[i][right]); // go down
        
        if(--right < left) break;
        for(int i = right; i >= left; i--) res.push_back(matrix[down][i]); // go left
        if(--down < up) break;
        for(int i = down; i <= up; i--) res.push_back(matrix[i][left]);
        if(++left > right) break;
    }
   return res;
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

//
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
    ugly[0] = 0;
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
<<<<<<< HEAD
    string tmpstr (number.size(), '0');
    //cout << stoi(number) << " ";  for debug
    if(number != tmpstr)
        res.push_back(stoi(number));
=======

>>>>>>> 84f23360f2eec80ea5f507a0bcbbca3e56f61ca6
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



int minIncrementForUnique(vector<int>& nums) {
    if(nums.size() < 2) return 0;
    sort(nums.begin(), nums.end());
    int ans = 0;
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] <= nums[i-1]) {
            ans += nums[i-1] - nums[i]+1;
            nums[i] = nums[i-1] + 1;
        }
    }
    return ans;
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

bool isMatch(string s, string p) {
    if(p.empty()) return s.empty();
    if(p[1] == '*') {
        return isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0] == '.')) &&
              isMatch(s.substr(1), p);
    } else {
        return !s.empty() && (s[0] == p[0] || p[0] == '.') && 
                (isMatch(s.substr(1), p.substr(1)));
    }
}

vector<int> exchange(vector<int>& nums) {
    if(nums.size() < 2) return nums;
    int l = 0, r = nums.size()-1;
    while(l < r) {
        while(l < r && (nums[l]&1)!=0)
            l++;
        while(l < r && (nums[r]&1) == 0)
            r--;
        if(l < r) swap(nums[l], nums[r]);
    }
    return nums;
}

bool validateStackSequences(vector<int>& pushed, vector<int>& poped) {
    stack<int> sk;
    vector<int>::iterator it = poped.begin();
    for(int i : pushed) {
        sk.push(i);
        while(sk.size() && sk.top() == *it) {
            sk.pop();
            it++;
        }
    }
    return it == poped.end() ? true : false;
}

vector<int> twoSum2(vector<int>& nums, int target) {
    vector<int> ans;
    if(nums.empty()) return ans;
    map<int, int> table;
    for(int i = 0; i < nums.size(); i++) {
        int x = target-nums[i];
        if(table.find(x) != table.end()) {
            ans.push_back(table[x]);
            ans.push_back(i);
        } else
            table[nums[i]] = i;
    }
    return ans;
}

int removeDuplicates(vector<int>& nums) {
    if(nums.size() < 2) return nums.size();
    int j = 0;
    for(int i = 1; i < nums.size(); i++) {
        if(nums[j] != nums[i])
            nums[++j] = nums[i];
    }
    return ++j;
}

/*
* 1.首先，让我们在任一位置 i 将 A(长度为m) 划分成两个部分：
*            leftA            |                rightA
*   A[0],A[1],...      A[i-1] |  A[i],A[i+1],...A[m - 1]
*
* 由于A有m个元素，所以有m + 1中划分方式(i = 0 ~ m)
*
* 我们知道len(leftA) = i, len(rightA) = m - i;
* 注意：当i = 0时，leftA是空集，而当i = m时，rightA为空集。
*
* 2.采用同样的方式，将B也划分为两部分：
*            leftB            |                rightB
*   B[0],B[1],...      B[j-1] |   B[j],B[j+1],...B[n - 1]
*  我们知道len(leftA) = j, len(rightA) = n - j;
*
*  将leftA和leftB放入一个集合，将rightA和rightB放入一个集合。再把这两个集合分别命名为leftPart和rightPart。
*
*            leftPart         |                rightPart
*   A[0],A[1],...      A[i-1] |  A[i],A[i+1],...A[m - 1]
*   B[0],B[1],...      B[j-1] |  B[j],B[j+1],...B[n - 1]
*
*   如果我们可以确认：
*   1.len(leftPart) = len(rightPart); =====> 该条件在m+n为奇数时，该推理不成立
*   2.max(leftPart) <= min(rightPart);
*
*   median = (max(leftPart) + min(rightPart)) / 2;  目标结果
*
*   要确保这两个条件满足：
*   1.i + j = m - i + n - j(或m - i + n - j + 1)  如果n >= m。只需要使i = 0 ~ m，j = (m+n+1)/2-i =====> 该条件在m+n为奇数/偶数时，该推理都成立
*   2.B[j] >= A[i-1] 并且 A[i] >= B[j-1]
*
*   注意:
*   1.临界条件：i=0,j=0,i=m,j=n。需要考虑
*   2.为什么n >= m ? 由于0 <= i <= m且j = (m+n+1)/2-i,必须确保j不能为负数。
*
*   按照以下步骤进行二叉树搜索
*   1.设imin = 0,imax = m，然后开始在[imin,imax]中进行搜索
*   2.令i = (imin+imax) / 2, j = (m+n+1)/2-i
*   3.现在我们有len(leftPart) = len(rightPart)。而我们只会遇到三种情况：
*
*      ①.B[j] >= A[i-1] 并且 A[i] >= B[j-1]  满足条件
*      ②.B[j-1] > A[i]。此时应该把i增大。 即imin = i + 1;
*      ③.A[i-1] > B[j]。此时应该把i减小。 即imax = i - 1;
*
* */
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    if(m > n) return findMedianSortedArrays(nums2, nums1);
    int imin = 0, imax = m;
    while(imin <= imax) {
        int i = (imin + imax) / 2;
        int j = (m+n+1)/2 - i;
        if(j != 0 && i != m && nums2[j-1] > nums1[i]) // i 需要增大
            imin = i + 1;
        else if(i != 0 && j != n && nums1[i-1] > nums2[j]) // i 需要减小
            imax = i-1;
        else { // 达到要求，并且将边界条件列出来单独考虑
            int maxleft = 0;
            if(i == 0)
                maxleft = nums2[j-1];
            else if(j == 0)
                maxleft = nums1[i-1];
            else maxleft = max(nums1[i-1], nums2[j-1]);
            if((m+n)%2 == 1) return maxleft; // 奇数的话不需要考虑右半部分

            int minright = 0;
            if(i == m) minright = nums2[j];
            else if (j == n) minright = nums1[i];
            else minright = min(nums2[j], nums1[i]);

            return (maxleft + minright) / 2.0;  // 如果是偶数则返回结果
        }   

    }
    return 0.0;
}

int binarySearch(vector<int>& nums, int target) {
    if(nums.size() < 1) return -1;
    int l = 0, r = nums.size()-1;
    while(l <= r) {
        int mid = l + (r-l)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] > target) r = mid-1;
        else l = mid+1;
    }
    return -1;
}

int numRookCaptures(vector<vector<char>>& board) {
    int rx, ry;
    for(int r = 0; r < 8; r++) {
        for(int c = 0; c < 8; c++) {
            if(board[r][c] == 'R') {
                rx = r; ry = c;
                break;
            }
        }
    }
    int cnt = 0;
    int tx = rx, ty = ry;
    // go up to count p
    while(--tx >= 0 && board[tx][ty] != 'B') {
        if(board[tx][ty] == 'p')  {
            cnt++; break;
        }
    }
    // go down to count p
    tx = rx; ty = ry;
    while(++tx < 8 && board[tx][ty] != 'B') {
        if(board[tx][ty] == 'p') {
            cnt++; break;
        }
    }
    // go left to count p
    tx = rx; ty = ry;
    while(--ty >= 0 && board[tx][ty] != 'B') {
        if(board[tx][ty] == 'p') {
            cnt++; break;
        }
    }
    // go right to count p
    tx = rx; ty = ry;
    while(++ty < 8 && board[tx][ty] != 'B') {
        if(board[tx][ty] == 'p')  {
            cnt++; break;
        }
    }
    return cnt;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> tmp;
    for(int i = 0; i < nums.size()-2; i++) {
        if(nums[i] > 0) break;
        if(i > 0 && nums[i] == nums[i-1]) continue;
        int l = i+1, r = nums.size()-1;
        while(l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if(sum < 0) {
                while(l < r && nums[l] == nums[++l]);
            } else if(sum > 0) {
                while(l < r && nums[r] == nums[--r]);
            } else {
                tmp.push_back(i); tmp.push_back(l); tmp.push_back(r);
                ans.push_back(tmp);
                tmp.clear();
                while(l < r && nums[l] == nums[++l]);
                while(l < r && nums[r] == nums[--r]);
            }
        }
    }
    return ans;
}

int threeSumCloset(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int ans = nums[0]+nums[1]+nums[2];
    for(int i = 0; i < nums.size(); i++) {
        int l = i+1, r = nums.size()-1;
        while(l < r) {
            int sum = nums[i]+ nums[l]+nums[r];
            if(abs(sum - target) < abs(ans - target)) 
                ans = sum;
            if(sum > target) 
                r--;
            else l++;
        }
    }
    return ans;
}
// 搜索旋转数组--无重复元素
int search(vector<int>& nums, int target) {
    if(nums.size() == 0) return -1;
    int l = 0, r = nums.size()-1;
    while(l <= r) {
        int mid = l+(r-l)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < nums[r]) {
            if(nums[mid] < target && target < nums[r])
                l = mid+1;
            else r = mid-1;
        } else {
            if(nums[l] <= target && target < nums[mid])
                r = mid-1;
            else l = mid+1;
        }
    }
}

int main() {
<<<<<<< HEAD

=======
    vector<vector<int>> nums = {{1, 2, 2}, {1, 2, 1}, {1, 1, 2}};
    vector<int> num = {1, 1, 2};
    for(vector<vector<int>>::iterator it = nums.begin(); it != nums.end(); it++) {
        if(*it == num) 
            cout << "found!" << endl;
    }
>>>>>>> 84f23360f2eec80ea5f507a0bcbbca3e56f61ca6
    return 0;
}