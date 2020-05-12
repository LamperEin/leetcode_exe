#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {

    }
    
    void add(int key) {

    }
    
    void remove(int key) {

    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {

    }
};

/** leetcode-217 存在重复元素
 *  input: [1, 2, 3, 1] -> output: true
 *  input: [1, 2, 3, 4] -> output: false
 */
bool containsDuplicate(vector<int>& nums) {
    if(nums.size() < 2) return false;
    unordered_set<int> table;
    for(int num : nums) {
        if(table.count(num) > 0) return true;
        table.insert(num);
    }
    return false;
}

/** leetcode-349 两个数组的交集
 *  input: nums1=[1, 2, 2, 1], nums2=[2, 2]
 *  output: [2]
 */
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    if(nums1.size() == 0 || nums2.size() == 0) return ans;
    unordered_set<int> hashset;
    for(int num : nums1) {
        if(hashset.count(num) == 0) 
            hashset.insert(num);
    }
    for(int num : nums2) {
        if(hashset.count(num) > 0) {
            bool found = false;
            for(int a : ans) {
                if(a == num) found = true;
            }
            if(!found) ans.push_back(num);
        }
    }
    return ans;
}


/** leetcode-     快乐数
 * 
 */
bool isHappy(int n) {
    if(n == 0) return false;
    unordered_set<int> hashset;
    while(n != 1) {
        int sum = 0;
        if(hashset.count(n) > 0) return false;
        int num = n, a;
        while(num != 0) {
            a = num%10;
            num /= 10;
            sum += a*a;
        }
        n = sum;
    }
    return true;
}

int main() {
    int n = 19;
    cout << isHappy(19) << endl;

    return 0;
}