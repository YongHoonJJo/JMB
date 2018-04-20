#include <cstdio>
#include <algorithm>
using namespace std;

int Rus[101], Kor[101];

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--) {
        int n;
        scanf("%d", &n);

        for(int i=0; i<n; i++) 
            scanf("%d", Rus+i);

        for(int i=0; i<n; i++) 
            scanf("%d", Kor+i);

        sort(Rus, Rus+n);
        sort(Kor, Kor+n);
        
        int ri=0, ki=0;
        int ans=0;

        while(ri < n && ki < n) {
            if(Rus[ri] <= Kor[ki]) {
                ans++; ri++; ki++;
            }
            else ki++;
        }
        printf("%d\n", ans);
    }
}
