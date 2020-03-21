#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int hammingWeight(uint32_t n) {
    int count = 0;
    while(n > 0) {
        count++;
        n = (n-1) & n;
    }
    return count;
}

bool canMeasureWater(int x, int y, int z) {
    if(x + y < z) return false;
    if(x == 0 || y == 0) return z == 0 || x+y == z;
    return z % __gcd(x, y) == 0;
}

int add(int a, int b) {
    int sum, carry;
    do {
        sum = a ^ b;
        carry = ((unsigned int)(a & b)) << 1;
        a = sum;
        b = carry;
    }while(b != 0);
    return a;
}

int lastRemaining(int n, int m) {
    int last = 0;
    for(int i = 2; i <= n; i++) {
        last = (last + m) % i;
    }
    return last;
}

int main() {  //0123456789
    int a = -1, b = 1;
    cout << add(a, b) << endl;
    return 0;
}