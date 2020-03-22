#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int cuttingRope(int n) {
    if(n <= 3) return n-1;
    int m = 1;
    while(n>4) {
        m *= 3;
        n -= 3;
    }
    return m*n;
}

int main() {


    return 0;
}