#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include <cmath>
#include <memory.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

int floyd[401][401]{};

int main()
{
	fastio;

	memset(floyd, 0x3f, sizeof(floyd));

	int v, e;
	cin >> v >> e;

	for(int i = 0; i < e; ++i)
	{
		int s, d, w;
		cin >> s >> d >> w;
		floyd[s][d] = w;
	}

	for(int k =1; k <=v; ++k)
		for(int i = 1; i <=v; ++i)
			for(int j =1; j<=v; ++j)
			{
				floyd[i][j] = min(floyd[i][k] + floyd[k][j], floyd[i][j]);
			}


	int mn = INF;
	for(int i = 1; i <= v; ++i)
		mn = min(floyd[i][i], mn);

	if (mn == INF)
		cout << -1;
	else
		cout << mn;


	return 0;
}


// S : 10 34
// U : 10 35
// T : 10 36
// C : 10 40
// Total :
