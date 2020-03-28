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

double myPow(double x, int n) {
    if(x == 0)
       return 0;
    long b = n;
    double ans = 1.0;
    if(b < 0) {
        x = 1 / x;
        b = - b;
    }
    while(b > 0) {
        if((b & 1) == 1) ans *= x;
        x *= x;
        b >>= 1; 
    }
    return ans;

}

int lastRemaining(int n, int m) {
    int last = 0;
    for(int i = 2; i <= n; i++) {
        last = (last + m) % i;
    }
    return last;
}

bool isPowerOfTwo(int n) {
    if(n <= 2) return true;
    return (n&(n-1)) == 0 ? true : false;
}

int main() {  //0123456789
    int n = 3;
    int n1 = 4;
    cout << isPowerOfTwo(n) << endl;
    cout << isPowerOfTwo(n1) << endl;
    return 0;
}