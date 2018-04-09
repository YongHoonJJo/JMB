#include <stdio.h>
#include <string.h>

int isFriend[11][11];
int n, hasPair[11];

int findA()
{
    for(int i=0; i<n; i++)
        if(!hasPair[i])
            return i;
    return n;
}

int picnic(int k)
{
    int a, ret = 0;
    if(k == n) return 1;
    
    a = findA();
    hasPair[a] = 1;

    for(int i=0; i<n; i++) {
        if(isFriend[a][i] && !hasPair[i]) {
            hasPair[i] = 1;
            ret += picnic(k+2);
            hasPair[i] = 0;
        }
    }
    hasPair[a] = 0;
    return ret;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--) {
        int m, ans=0;
        scanf("%d%d", &n, &m);
        
        memset(isFriend, 0, sizeof(isFriend));
        while(m--) {
           int a, b;
           scanf("%d%d", &a, &b);
           isFriend[a][b] = isFriend[b][a] = 1;
        }
        printf("%d\n", picnic(0));
    }
    return 0;
}
