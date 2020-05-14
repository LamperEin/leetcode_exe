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


void quickSort(vector<int>& nums, int l, int r) {
    if(l > r) return;
    int i = l, j = r, x = nums[l];
    while(i < j) {
        while(i < j && nums[j] >= x)
            j--;
        if(i < j) nums[i++] = nums[j];

        while(i < j && nums[i] <= x)
            i++;
        if(i < j) nums[j--] = nums[i];
    }
    a[i] = x;
    quickSort(nums, l, i-1);
    quickSort(nums, i+1, r);
}

int quickFind(vector<int>& a, int left, int right, int k) {
    int i = left, j = right, pivot = a[left];

    while(i < j) {
        while(i < j && a[j] >= pivot)
            j--;
        if(i < j) a[i++] = a[j];

        while(i < j && a[i] <= pivot)
            i++;
        if(i < j) a[i++] = a[j];
    }
    a[i] = pivot;
    int ge_pivot = right - i;
    if(k - ge_pivot - 1 == 0) // if pivot is kth num
        return pivot;
    else if(k - ge_pivot - 1 > 0) // if the count of num greate than pivot is less than k, find kth num in left part
        return quickFind(a, left, i-1, k-ge_pivot-1);
    else 
        return quickFind(a, i+1, right, k); // find kth num in right part
}

int findKth(vector<int> a, int n, int k) {
    return quickFind(a, 0, n-1, k);
}

int main() {


    return 0;
}