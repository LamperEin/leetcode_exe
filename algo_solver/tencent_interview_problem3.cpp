#include<stdio.h>
#include<vector>
using namespace std;
 
long long n, m, total, sum, offset, num;
 
vector<long long> count(n + 1);
vector<long long> l(total);
vector<long long> l_copy(total);
vector<long long> max_c(n + 1);
void mergesort(long long index, long long size)
{
    if(size == 0)
    {
        l_copy[index] = l[index];
        return;
    }
    vector<long long> l_copy2(1<<size);
    long long st1 = index, st2 = index + (1 << (size - 1) ), ed1 = st2, ed2 = index + (1 << size);
    long long pos = 0, p1 = st1, p2 = st2;
    mergesort(st1, size - 1);
    mergesort(st2, size - 1);
    while(p1 < ed1 && p2 < ed2)
    {
        if(l_copy[p1] == l_copy[p2]){
            long long c1 = 1, c2 = 1;
            l_copy2[pos++] = l_copy[p1++];
            l_copy2[pos++] = l_copy[p2++];
            while(p1 < ed1 && l_copy[p1] == l_copy[p1 - 1]) 
                l_copy2[pos++] = l_copy[p1++], ++c1; 
            while(p2 < ed2 && l_copy[p2] == l_copy[p2 - 1]) 
                l_copy2[pos++] = l_copy[p2++], ++c2;
            max_c[size] -= c1 * c2;
            count[size] += (ed1 - p1) * c2;
        }
        else if(l_copy[p1] < l_copy[p2]){
            l_copy2[pos++] = l_copy[p1++];
        }
        else {
            count[size] += ed1 - p1;
            l_copy2[pos++] = l_copy[p2++];
        }
    }
    if(p1 == ed1) {
        while(p2 != ed2) 
            l_copy2[pos++] = l_copy[p2++];
    } else if(p2 == ed2) { 
        while(p1 != ed1) 
            l_copy2[pos++] = l_copy[p1++];
    }
    for(long long i = st1; i < ed2; ++i) 
        l_copy[i] = l_copy2[i - st1]; 
}
 
int main()
{   
    scanf("%lld", &n);
    total = (long long)1 << n;
    count.resize(n + 1);
    max_c.resize(n + 1);
    l.resize(total);
    l_copy.resize(total);
    for(long long i = 0; i < total; ++i) 
        scanf("%lld", &l[i]);
    max_c[0] = 1;
    for(long long i = 1; i <= n; ++i) 
        max_c[i] = (long long)1 <<(n + i  - 2);//(1 << 2 * (i - 1) ) * ( 1 << (n - i))
     
    mergesort(0, n);
     
    scanf("%lld", &m);
    for(long long i = 0; i < m; ++i)
    {
        scanf("%lld", &num);
        sum = 0;
        for(long long j = 1; j <= n; ++j)
        {
            if(j <= num) count[j] = max_c[j] - count[j];
            sum += count[j];
        }
        printf("%lld\n", sum);
    }
}