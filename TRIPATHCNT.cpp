#include <stdio.h>
#include <string.h>

int n;
int a[101][101];
int d[101][101], e[101][101];

int max(int a, int b)
{
    return a > b ? a : b;
}

int PathSum(int r, int c)
{
    int ret;
    if(!a[r][c]) return 0;
    if(r == n) return a[r][c];
    if(e[r][c]) return e[r][c];
    
    ret = max(PathSum(r+1, c), PathSum(r+1, c+1));
    return e[r][c] = ret + a[r][c];
}

int PathCnt(int r, int c)
{   
    int ret=0;
    int a, b;
    if(r == n) return 1;
    if(d[r][c]) return d[r][c];

    a = PathSum(r+1, c);
    b = PathSum(r+1, c+1);
    if(a == b) ret += (PathCnt(r+1, c) + PathCnt(r+1, c+1));
    else ret += (a > b ? PathCnt(r+1, c) : PathCnt(r+1, c+1));

    return d[r][c] = ret; 
}

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--) {
        scanf("%d", &n);

        for(int i=1; i<=n; i++)
            for(int j=1; j<=i; j++)
                scanf("%d", &a[i][j]);
        
        memset(d, 0, sizeof(d));
        memset(e, 0, sizeof(e));
        printf("%d\n", PathCnt(1, 1));
    }
    return 0;
}
