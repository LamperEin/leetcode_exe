#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void merge(vector<int>& A, int m, vector<int>& B, int n) {
    int i = m-1, j = n-1;
    int index = m+n-1;
    while(j >= 0 && i >= 0) {
        if(A[i] >= B[j])
            A[index--] = A[i--];
        else 
            A[index--] = B[j--];
    }
    while(j >= 0) A[index--] = B[j--];
}

int reversePairsCore(vector<int>& nums, int l, int r) {
    if(r-l <= 1) return 0;
    int mid = (r+l)/2;
    vector<int> tmp;
    int ans = reversePairsCore(nums, l, mid)+ reversePairsCore(nums, mid, r);
    int i = l, j = mid;
    while(i < mid && j < r) {
        if(nums[i] > nums[j]) {
            ans += mid - i;
            tmp.push_back(nums[j++]);
        } else {
            tmp.push_back(nums[i++]);
        }
    }
    while(i < mid) tmp.push_back(nums[i++]);
    while(j < mid) tmp.push_back(nums[j++]);
    copy(tmp.begin(), tmp.end(), nums.begin()+l);
    return ans;
}

int reversePairs(vector<int>& nums) {
    return reversePairsCore(nums, 0, nums.size());
}

int main() {


    return 0;
}