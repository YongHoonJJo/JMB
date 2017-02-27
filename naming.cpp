#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX	400001

char str[MAX];
vector<int> v;

int main()
{
	int len;
	char *t = str;
	int i, j, pi[MAX]={0};

	gets(str);
	len = strlen(str);
	gets(t+len);

	len = len+strlen(t+len);
	for(i=1, j=0; i<len; i++) {
		while(j>0 && str[i]!=str[j]) j=pi[j-1];
		if(str[i]==str[j]) pi[i]=++j;
	}

	j = len;
	while(j) {
		v.push_back(j);
		j=pi[j-1];
	}
	
	sort(v.begin(), v.end());
	
	for(i=0; i<v.size(); i++)
		printf("%d ", v[i]);

	return 0;
}
