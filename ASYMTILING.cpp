#include <stdio.h>

const int MOD = 1000000007;

int d[101];

int tiling(int n)
{
    if(n <= 1) return 1;
    if(d[n]) return d[n];
    return d[n] = (tiling(n-1) + tiling(n-2)) % MOD;
}

int asymtiling(int n)
{
    int ret;
    ret = tiling(n/2) % MOD;
    if(n&1) return ret;
    ret += ((tiling((n/2)-1)) % MOD);
    return ret%MOD;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", (tiling(n)-asymtiling(n)+MOD)%MOD);
    }
    return 0;
}
