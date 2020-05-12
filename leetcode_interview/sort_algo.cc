#include <iostream>
#include <vector>

using namespace std;


// quickSort
void __quickSort(vector<int>& nums, int l, int r) {
    if(r <= l) return;
    int j = l, v = nums[l];
    for(int i = l+1; i <= r; ++i) {
        if(nums[i] < v) {
            j++;
            swap(nums[j], nums[i]);
        }
    }
    swap(nums[l], nums[j]);
    __quickSort(nums, l, j-1);
    __quickSort(nums, j+1, r);
}

void quickSort(vector<int>& nums) {
    __quickSort(nums, 0, nums.size()-1);
}

// merge sort
void __mergetSort(vector<int>& nums, int l, int r) {
    if(l >= r) return;
    int mid = l + (r-l)/2;
    __mergetSort(nums, l, mid);
    __mergetSort(nums, mid+1, r);
    vector<int> tmp;
    int i = l, j = mid+1;
    while(i <= mid && j <= r) {
        if(nums[i] <= nums[j]) {
            tmp.push_back(nums[i]);
            i++;
        } else {
            tmp.push_back(nums[j]);
            j++;
        }
    }
    while(i <= mid) tmp.push_back(nums[i++]);
    while(j <= r) tmp.push_back(nums[j++]);
    copy(tmp.begin(), tmp.end(), nums.begin()+l);
}

void mergeSort(vector<int>& nums) {
    __mergetSort(nums, 0, nums.size()-1);
}


void selectSort(vector<int>& nums) {

}


void insertSort(vector<int>& nums) {
    for(int i = 1; i < nums.size(); i++) {
        int j = i;
        while(j >= 0 && nums[j] < nums[j-1]) {
            swap(nums[j], nums[j-1]);
            --j;
        }
    }
}

void bubbleSort(vector<int>& nums) {
    
}


void CountSort(vector<int>& nums) {

}


void shellSort(vector<int>& nums) {

}


int main() {
    vector<int> nums = {3, 2, 1, 0, 6, 9, 8, 7, 4, 5};
    //mergeSort(nums);
    quickSort(nums);
    for(int num : nums)
        cout << num << " ";
    cout << endl;
    return 0;
}