#include <stdio.h>

int n;
int a[501], d[501];

int max(int a, int b)
{
    return a > b ? a : b;
}

int lis(int s)
{
    int ret = 0;
    if(s == n-1) return 1;
    if(d[s]) return d[s];
    for(int i=s+1; i<n; i++) {
        if(a[s] < a[i])
            ret = max(ret, lis(i)); 
    }
    return d[s] = ret+1; 
}

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--) {
        int ans=0;
        scanf("%d", &n);

        for(int i=0; i<n; i++) {
            scanf("%d", a+i);
            d[i] = 0;
        }
        for(int i=0; i<n; i++)
            ans = max(ans, lis(i));
        printf("%d\n", ans);
    }

    return 0;
}
