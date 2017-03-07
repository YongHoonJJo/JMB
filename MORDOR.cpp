#include <stdio.h>

int Max(int segMax[], int L, int R, int nodeNum, int nodeL, int nodeR)
{
	int a, b, mid=(nodeL+nodeR)/2;
	if(R < nodeL || nodeR < L) return 0;
	if(L <= nodeL && nodeR <= R) return segMax[nodeNum];
	
	a = Max(segMax, L, R, nodeNum*2, nodeL, mid);
	b = Max(segMax, L, R, nodeNum*2+1, mid+1, nodeR);
	return a > b ? a : b;
}

int Min(int segMin[], int L, int R, int nodeNum, int nodeL, int nodeR)
{
	int a, b, mid=(nodeL+nodeR)/2;
	if(R < nodeL || nodeR < L) return 20000;
	if(L <= nodeL && nodeR <= R) return segMin[nodeNum];
	
	a = Min(segMin, L, R, nodeNum*2, nodeL, mid);
	b = Min(segMin, L, R, nodeNum*2+1, mid+1, nodeR);
	return a < b ? a : b;
}

int main()
{
	int tc;
	scanf("%d", &tc);

	while(tc--) {
		int segMax[300000]={0}, segMin[300000]={0};
		int sIdx=1;

		int i, n, q;
		int s, e;
		scanf("%d %d", &n, &q);

		while(sIdx < n)
			sIdx <<= 1;

		for(i=0; i<n; i++) {
			scanf("%d", &segMax[sIdx+i]);
			segMin[sIdx+i] = segMax[sIdx+i];
		}
		
		s = sIdx>>1; e = sIdx;
		while(s) {
			for(i=s; i<e; i++) {
				segMin[i] = segMin[i*2]<segMin[i*2+1] ? segMin[i*2] : segMin[i*2+1];
				segMax[i] = segMax[i*2]>segMax[i*2+1] ? segMax[i*2] : segMax[i*2+1];
			}
			e = s;
			s >>= 1;
		}

		while(q--) {
			int a, b;
			scanf("%d %d", &a, &b);
			printf("%d\n", Max(segMax, a, b, 1, 0, sIdx-1)-Min(segMin, a, b, 1, 0, sIdx-1));
		}
	}

	return 0;
}
