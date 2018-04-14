#include <stdio.h>
#define MOD 1000000007

int d[101];

int tiling2(int n)
{
    if(n == 0) return 1;
    if(n < 0) return 0;
    if(d[n]) return d[n];
    
    return d[n] = (tiling2(n-1) + tiling2(n-2)) % MOD;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", tiling2(n));
    }   
    
    return 0;
}
