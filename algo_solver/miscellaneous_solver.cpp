#include <iostream>
#include <algorithm>

using namespace std;

int hammingWeight(uint32_t n) {
    int count = 0;
    while(n > 0) {
        count++;
        n = (n-1) & n;
    }
    return count;
}


int main() {
    uint32_t a = 67;
    int res = hammingWeight(a);
    cout << res <<endl;
    return 0;
}