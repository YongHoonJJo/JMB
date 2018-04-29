#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;

char boggle[5][6];
int di[]={1, 1, 0, -1, -1, -1, 0, 1};
int dj[]={0, 1, 1, 1, 0, -1, -1, -1};

int sNum = 1;
map<string, int> msi;
int d[5][5][10000];

int check(int curI, int curJ, char *word)
{
	if(*(word+1) == 0) return true;

    int num;
    if(msi.find(word) == msi.end()) {
        msi[word] = sNum;
        num = sNum++;
    }
    else num = msi[word];
    
    int &ret = d[curI][curJ][num];
    if(ret != 0) return ret;

	for(int k=0; k<8; k++) {
		int nextI = curI+di[k];
		int nextJ = curJ+dj[k];
		if((0 <= nextI && nextI < 5) && (0 <= nextJ && nextJ < 5)) {
			if(boggle[nextI][nextJ] == *(word+1) && check(nextI, nextJ, word+1) == 1)
                return ret = 1;
		}
	}
    return ret = -1;
}

bool BOGGLE(char *word)
{
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            if(boggle[i][j] == *word && check(i, j, word) == 1)
                return true;
    return false;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--) {
        for(int i=0; i<5; i++)
            scanf("%s", boggle[i]);
        
        memset(d, 0, sizeof(d));

        int n;
        scanf("%d", &n);
        while(n--) {
            char word[11];
            scanf("%s", word);
            printf("%s ", word);
            BOGGLE(word) ? puts("YES") : puts("NO");
        }
    }
}	
