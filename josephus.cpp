#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int n, k;
		scanf("%d %d", &n, &k);
		vector<int> v(n, 0);
		
		int t=0, mod=n;
		while(n != 2) {
			int gap=k;
			v[t] = 1;
			while(gap--) {
				t++;
				t%=mod;
				if(v[t]) gap++;
			}
			n--;
		}
		
		for(int i=0; i<mod; i++)
			if(!v[i])
				printf("%d ", i+1);
		puts("");
	}
}
