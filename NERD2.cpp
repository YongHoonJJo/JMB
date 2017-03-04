#include <cstdio>
#include <vector>
#include <map>
using namespace std;

bool isDominated(map<int, int> &coords, int x, int y)
{
	map<int, int>::iterator it = coords.lower_bound(x);

	if(it == coords.end()) return false;

	return y < it->second;
}

void removeDominated(map<int, int> &coords, int x, int y)
{
	map<int, int>::iterator it = coords.lower_bound(x);

	if(it == coords.begin()) return;
	--it;

	while(1) {
		if(it->second > y) break;
		if(it == coords.begin()) {
			coords.erase(it);
			break;
		}
		else {
			map<int, int>::iterator jt = it;
			--jt;
			coords.erase(it);
			it = jt;
		}
	}	
}

int main()
{
	int tc;
	scanf("%d", &tc);

	while(tc--) {
		int i, n, ans=0;
		scanf("%d", &n);

		map<int, int> coords;
		for(i=0; i<n; i++) {
			int p, q;
			scanf("%d %d", &p, &q);
			if(!isDominated(coords, p, q)) {
				removeDominated(coords, p, q);
				coords[p] = q;
			}
			ans += coords.size();			
		}
		printf("%d\n", ans);
	}
}
