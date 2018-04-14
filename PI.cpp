#include <stdio.h>
#include <string.h>
#define INF 1e9

char p[10001];
int len, d[10001];

int min(int a, int b)
{
    return a < b ? a : b;
}

int isSame(int s, int cnt)
{
    for(int i=s; i<s+cnt-1; i++)
        if(p[i] != p[i+1]) 
            return 0;
    return 1;
}

int isInc(int s, int cnt)
{
    for(int i=s; i<s+cnt-1; i++)
       if(p[i]+1 != p[i+1])
           return 0;
    return 1;
}

int isDec(int s, int cnt)
{
    for(int i=s; i<s+cnt-1; i++)
        if(p[i]-1 != p[i+1])
            return 0;
    return 1;
}

int isAlter(int s, int cnt)
{
    if(cnt == 3) {
        if(p[s] == p[s+2]) return 1;
    }
    else if(cnt == 4) {
        if(p[s] == p[s+2] && p[s+1] == p[s+3]) return 1;
    }
    else if(cnt == 5) {
        if(p[s] == p[s+2] && p[s+2] == p[s+4] && p[s+1] == p[s+3])
            return 1;
    }
    return 0;
}

int isSeq(int s, int cnt)
{
    int diff = p[s+1] - p[s];
    for(int i=s; i<s+cnt-1; i++)
        if(p[i]+diff != p[i+1])
            return 0;
    return 1;
}
    

int getScore(int s, int cnt)
{
    if(isSame(s, cnt)) return 1;
    if(isInc(s, cnt) || isDec(s, cnt)) return 2;
    if(isAlter(s, cnt)) return 4;
    if(isSeq(s, cnt)) return 5;
    return 10;
}


int pi(int s)
{
    int k, ret = INF;
    if(s == len) return 0;
    if(s > len) return INF;
    if(d[s]) return d[s];

    for(int i=3; i<=5; i++) {
        k = getScore(s, i);
        ret = min(ret, pi(s+i)+k);
    }

    return d[s] = ret;
}


int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--) {
        scanf("%s", p);
    
        len = strlen(p);
        memset(d, 0, sizeof(d));

        printf("%d\n", pi(0)); 
    }
    return 0;
}
