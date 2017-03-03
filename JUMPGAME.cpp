#include <cstdio>

int g[101][101], d[101][101];

int jump(int y, int x)
{
	int i, ans=0;
	int &ret = d[y][x];
	if(y < 1 || x < 1) return 0;
	if(y == 1 && x == 1) return 1;
	if(ret) return ret;
	

	for(i=1; i<x; i++)
		if(g[y][x-i]==i)
			ans += jump(y,x-i);
	
	for(i=1; i<y; i++)
		if(g[y-i][x]==i)
			ans += jump(y-i,x);
	return ret = ans;
}

int main()
{
	int tc;
	scanf("%d", &tc);

	while(tc--) {
		int i, j, n;
		scanf("%d", &n);
		
		for(i=1; i<=n; i++) {
			for(j=1; j<=n; j++) {
				scanf("%d", &g[i][j]);
				d[i][j] = 0;
			}
		}
		
		jump(n, n) ? puts("YES") : puts("NO");
	}
}
