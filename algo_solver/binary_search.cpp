#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int binarySearch1(vector<int>& nums, int target) {
    if(nums.size() < 1) return-1;
    int l = 0, r = nums.size()-1;
    while(l <= r) {
        int mid = l + (r-l)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) l = mid+1;
        else r = mid-1;
    }
    return -1;
}

int binarySearch2(vector<int>& nums, int target) {
    if(nums.size() == 0) return -1;
    int l = 0, r = nums.size()-1;
    while(l < r) {
        int mid = l + (r-l)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) l = mid+1;
        else r = mid;
    }
    if(l!=nums.size() && nums[l] == target) return l;
    return -1;
}

int findPeakElement(vector<int>& nums) {
    if(nums.size() < 3) return -1;
    int l = 0, r = nums.size()-1;
    


}

int main() {
    
    
    
    return 0;
}