#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> order;
vector<bool> visited;
// 알파벳 각 글자에 대한 인접행렬
// 간선(i, j)는 알파벳 i가 j보다 앞에 와야 함을 나타낸다.
vector<vector<int> > v;

// 주어진 단어들로부터 알파벳 간의 선후관계 그래프를 생성
void makeGraph(const vector<string> &words)
{
	v = vector<vector<int> >(26, vector<int>(26, 0));
	for(int i=1; i<words.size(); i++) {
		int len = min(words[i-1].size(), words[i].size());
		for(int k=0; k<len; k++) {
			int a = words[i-1][k]-'a';
			int b = words[i][k]-'a';
			if(a != b) {
				v[a][b] = 1;
				break;
			}
		}
	}
}

// order는 dfs가 종료하는 순서를 기록
void dfs(int s)
{
	visited[s] = 1;
	for(int i=0; i<v.size(); i++)
		if(v[s][i] && !visited[i])
			dfs(i);
	order.push_back(s);
}

// v에 주어진 그래프를 위상정렬한 결과를 반환
// 그래프가 DAG가 아니면 빈 벡터를 반환
vector<int> topologicalSort() {
	int i, j, n=v.size();
	visited = vector<bool>(n, 0);
	
	order.clear();
	for(i=0; i<n; i++)
		if(!visited[i])
			dfs(i);
	reverse(order.begin(), order.end());
	
	// DAG가 아니면 정렬결과에 역방향 간선이 존재
	for(i=0; i<n; i++)
		for(j=i+1; j<n; j++)
			if(v[order[j]][order[i]])
				return vector<int>();
	return order;
}

int main()
{
	int tc;
	scanf("%d", &tc);

	while(tc--) {
		int n;
		vector<string> words;

		scanf("%d", &n);
		while(n--) {
			string s;
			cin >> s;
			words.push_back(s);
		}

		makeGraph(words);
		vector<int> ans = topologicalSort();

		n = ans.size();
		if(!n)
			puts("INVALID HYPOTHESIS");
		else {
			for(int i=0; i<n; i++) {
				printf("%c", ans[i]+'a');
			}
			puts("");
		}
	}

}
