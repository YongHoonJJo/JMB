#include <stdio.h>

const int MOD = 10000000;

int d[101][101];

int poly(int up, int n)
{
    int ret = 0;
    if(n == 0) return 1;
    if(n == 1) return up;
    if(d[up][n]) return d[up][n];

    for(int down=1; down<=n; down++) {
        ret += (poly(down, n-down)*(up+down-1));
        ret %= MOD;
    }
    return d[up][n] = ret; 
}   

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--) {
        int n, ans=0;
        scanf("%d", &n);

        for(int i=1; i<=n; i++) {
            ans += poly(i, n-i);
            ans %= MOD;
        }
        printf("%d\n", ans);
    }
     
    return 0;
}
