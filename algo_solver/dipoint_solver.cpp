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
vector<int> twoSum(vector<int>& nums, int target) { // for sorted array
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
            r--;
        }
    }
    return res;
}


int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(2);
    //sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) 
        cout << nums[i] << endl;
    cout << arrayPairSum(nums) << endl;

    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(1);
    cout << arrayPairSum(nums1) << endl;
    return 0;
}