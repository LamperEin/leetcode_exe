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


int main() {


    return 0;
}