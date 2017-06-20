#include <cstdio>
#include <vector>
using namespace std;

int n, y[100], x[100], r[100];
int depth, vertex;
vector<bool> visited;
vector<vector<int> > g;

int sqr(int x) { return x*x; }

int sqrdist(int a, int b) 
{ 
	return sqr(y[a]-y[b])+sqr(x[a]-x[b]);
}

bool encloses(int a, int b)
{
	return r[a]>r[b] && sqrdist(a, b)<sqr(r[a]-r[b]);
}

bool isChild(int p, int c)
{
	if(!encloses(p, c)) return false;
	for(int i=0; i<n; i++)
		if(i != p && i != c && encloses(p, i) && encloses(i, c))
			return false;
	return true;
}

void getTree(int root)
{
	for(int ch=0; ch<n; ch++) {
		if(isChild(root, ch)) {
			g[root][ch] = g[ch][root] = 1;
			getTree(ch);
		}
	}
}

void dfs(int s, int cnt)
{
	visited[s] = 1;

	if(depth < cnt) {
		vertex = s;
		depth = cnt;
	}

	for(int i=0; i<n; i++) {
		if(!visited[i] && g[s][i])
			dfs(i, cnt+1);
	}					

}

int main()
{
	int tc;
	scanf("%d", &tc);

	while(tc--) {
		scanf("%d", &n);

		for(int i=0; i<n; i++) {
			scanf("%d%d%d", x+i, y+i, r+i);
		}
		g.clear();
		g = vector<vector<int> >(n, vector<int>(n, 0));	
		
		getTree(0);
		visited.clear();
		visited = vector<bool>(n, 0);
	
		vertex = depth = 0;
		dfs(0, 0);
		
		visited.clear();
		visited = vector<bool>(n, 0);
		dfs(vertex, 0);
	
		printf("%d\n", depth);
	}
}
