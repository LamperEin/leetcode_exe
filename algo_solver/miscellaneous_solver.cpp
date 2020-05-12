#include <iostream>
#include <algorithm>
#include <vector>
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

/** leetcode-461 汉明距离
 *  @param: x=1, y=4 @return:2
 */
int hammingDistance(int x, int y) {
    int z = x^y;
    int ans = 0;
    while(z) {
        ans += z&1;
        z = z>>1;
    }
    return ans;
}

bool canMeasureWater(int x, int y, int z) {
    if(x + y < z) return false;
    if(x == 0 || y == 0) return z == 0 || x+y == z;
    return z % __gcd(x, y) == 0;
}

int add(int a, int b) {
    while(b!=0) {
        int tmp = a^b;
        b = ((unsigned int)a&b)<<1;
        a = tmp;
    }
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
/** x的平方根
 *  input: 4 -> output: 2
 *  input: 8 -> output: 2
*/
int mysqrt(int n) {
    long i;
    for(i = 1; i <= n; i++) {
        if(i*i == n)
            return i;
        if(i*i > n)
            break;
    }
    return i-1;
}

/** leetcode-279 完全平方数
 *  @param: n=12  -> @return: 3
 *  @note: 12 = 4+4+4
 */
int numSquares(int n) {
    while(0 == n%4) n /= 4;
    if(7 == n%8) return 4;
    for(int i = 0; i*i < n; i++) {
        int j = pow(n-i*i, 0.5);
        if(n == i*i+j*j) return 2;
    }
    return 3;
}


int main() {  //0123456789
  

    return 0;
}