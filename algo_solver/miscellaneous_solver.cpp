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

    return 0;
}