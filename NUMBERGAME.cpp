#include <stdio.h>
#include <string.h>

const int INF = 1e9;

int a[51];
int d[51][51];

int max(int a, int b)
{
    return a > b ? a : b;
}

int gameNum(int s, int e)
{
    int ret=0;
    if(s == e) return a[s];
    if(s > e) return 0;
    if(d[s][e] != INF) return d[s][e];

    ret = max(a[s]-gameNum(s+1, e), a[e]-gameNum(s, e-1));
    if(e-s >= 1) ret = max(ret, -gameNum(s+2, e));
    if(e-s >= 1) ret = max(ret, -gameNum(s, e-2));

    return d[s][e] = ret;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--) {
        int n;
        scanf("%d", &n);

        for(int i=0; i<n; i++) {
            scanf("%d", a+i);
            for(int j=0; j<n; j++) 
                d[i][j] = INF;
        }

        
        printf("%d\n", gameNum(0, n-1));
    }
    return 0;
}
