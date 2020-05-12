#include <iostream>
#include <algorithm>
#include <string> 
#include <vector>
#include <map>

using namespace std;

void reverseString(vector<char>& s) {
    char temp;
    int tail = s.size()-1, head = 0;
    if (s.size() > 1) {
        while(tail > head) {
            temp = s[head];
            s[head++] = s[tail];
            s[tail--] = temp;
        }
    }

}

//input: [1, 4, 3, 2] ouput: 4
// n = 2, max_sum = min(1, 2) + min(3, 4)
int arrayPairSum(vector<int>& nums) {
    int sum;
    
    /*sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i+=2)
        sum += min(nums[i], nums[i+1]);*/

    return sum;
}

//input: nums = [2, 7, 11, 15], target = 9
//ouput: [1, 2]
// 2 + 7 = 9. index1 = 1, index2 = 2;
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    int l = 0, r = nums.size()-1;
    while(l < r) {
        int tmp = nums[l] + nums[r];
        if(tmp == target) {
            res.push_back(l+1);
            res.push_back(r+1);
            break;
        } else if (tmp < target) {
            l++;
        } else {
            r++;
        }
    }
    return res;
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
    int minlen = 0, j = 0;
    int sum = 0;
    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        while(sum >= s) {
            minlen = minlen == 0 ? i-j+1 : min(minlen, i-j+1);
            sum -= nums[j++];
        }
    }
    return minlen;
}

/** leetcode-26 删除排序数组中的重复项
 *  input：[1, 1, 2] -> output: 2
 */
int removeDuplicates(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    int k = 0;
    int tmp = nums[0];
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] != tmp){
            k++;
            nums[k] = nums[i];
            tmp = nums[k];
        }
    }
    return k+1;
}

/** leetcode-80 删除排序数组中的重复项II
 *  input: [1, 1, 1, 2, 2, 3] -> output: 5
 *  [1, 1, 1, 2, 2, 3] -> [1, 1, 2, 2, 3]
 */
int removeDuplicates2(vector<int>& nums) {
    int ans = 0;
    return ans;
}

/** leetcode-283 移动零
 *  input: [0, 1, 0, 3, 12] -> output: [1, 3, 12, 0, 0]
 */
void moveZeroes(vector<int>& nums) {
    for(int nearZoreidx = 0, cur = 0; cur < nums.size(); cur++)
        if(nums[cur] != 0)
            swap(nums[nearZoreidx++], nums[cur]);
}

/** leetcode-287 寻找重复数 (循环检测)
 *  @param: a vector contains at least one duplicate num
 *  @return: the duplicate num
 */
int findDuplicate(vector<int>& nums) {
    // find the intersection point if the two runners
    int slow = nums[0];
    int fast = nums[0];
    dow {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while(slow != fast);
    
    // find the "entrance" to the cycle
    int ptr1 = num[0];
    int ptr2 = slow;
    while(ptr1 != ptr2) {
        ptr1 = num[ptr1];
        ptr2 = num[ptr2];
    }
    return ptr1;
}

int main() {

    return 0;
}