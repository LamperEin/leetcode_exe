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

int binarySearch(int arr[], int len, int target) {
    // find target in a sorted arr[l...r]
    int l = 0, r = len-1;
    while(l <= r) {

        int mid = l + (r-l)/2;
        if(arr[mid] == target)
            return mid;
        if(arr[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
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
    int a[] = {1, 2, 4, 5, 7, 8, 9, 10};
    cout << binarySearch(a, 8, 9) << endl;

    return 0;
}