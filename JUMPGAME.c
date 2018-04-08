#include <stdio.h>

int n;
int g[101][101], d[101][101];

int jump(int r, int c)
{
    if(r >= n || c >= n) return 0;
    if(r == n-1 && c == n-1) return 1;
    if(d[r][c] != -1) return d[r][c];
    return d[r][c] = jump(r+g[r][c], c) || jump(r, c+g[r][c]);
}

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--) {
        scanf("%d", &n);

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                scanf("%d", &g[i][j]);
                d[i][j] = -1;
            }
        }

        jump(0, 0) ? puts("YES") : puts("NO");
    }
    return 0;
}
