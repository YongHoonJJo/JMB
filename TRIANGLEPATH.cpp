#include <stdio.h>

int n;
int g[101][101];
int d[101][101];

int max(int a, int b)
{
    return a > b ? a : b;
}

int trianglePath(int r, int c)
{
    int ret;
    if(!g[r][c]) return 0;
    if(r == n-1) return g[r][c];

    if(d[r][c] != -1) return d[r][c];

    ret = trianglePath(r+1, c);
    ret = max(ret, trianglePath(r+1, c+1)); 
    return d[r][c] = g[r][c]+ret; 
}

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--) {
        scanf("%d", &n);

        for(int i=0; i<n; i++) {
            for(int j=0; j<=i; j++) {
                scanf("%d", &g[i][j]);
                d[i][j] = -1;
            }
        }
    
        printf("%d\n", trianglePath(0, 0));
    }
    return 0;
}
