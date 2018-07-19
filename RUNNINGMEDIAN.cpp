#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef long long int lli;
const lli MOD = 20090711LL; 

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--) {
        int n, b;
        lli a;
        scanf("%d%lld%d", &n, &a, &b);

        lli ai = 1983LL;
        lli ans = ai;
        priority_queue<lli> minH, maxH;
        maxH.push(ai);
        for(int i=1; i<n; i++) {
            ai = (1LL*ai*a+b)%MOD; 
            
            if(i&1) minH.push(-ai);
            else maxH.push(ai);
           
            if(-minH.top() < maxH.top()) {
                int a = maxH.top(); maxH.pop();
                int b = -minH.top(); minH.pop();
                maxH.push(b);
                minH.push(-a);
            }
            ans = (ans + maxH.top()) % MOD;
       }
        printf("%lld\n", ans);
    }
    return 0;
}
