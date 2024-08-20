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

// 1. Union Find로 위원회 구함
// 2. 전달 경로가 최소. 플로이드로 판단.

int p[101];

int Find(int n)
{
	if (p[n] < 0) return n;
	return p[n] = Find(p[n]);
}

bool Union(int parent, int child)
{
	parent = Find(parent);
	child = Find(child);

	if (parent == child) return false;

	p[parent] += p[child];
	p[child] = parent;

	return true;
}

int floyd[101][101]{};

int main()
{
	fastio;

	memset(p, -1, sizeof(p));
	memset(floyd, INF, sizeof(floyd));

	int v, e;
	cin >> v >> e;

	for(int i = 0; i < e; ++i)
	{
		int a, b;
		cin >> a >> b;
		floyd[a][b] = 1;
		floyd[b][a] = 1;
	}

	for (int i = 1; i <= v; ++i)
		for (int j = i + 1; j <= v; ++j)
			if(floyd[i][j] != INF)
				Union(i, j);

	vector<int> parents;
	for (int i = 1; i <= v; ++i)
		if (p[i] < 0)
			parents.push_back(i);

	cout << parents.size() << "\n";

	for (int k = 1; k <= v; ++k)
		for (int i = 1; i <= v; ++i)
			for (int j = 1; j <= v; ++j)
					floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);

	vector<int> leaders;
	for(auto parent : parents)
	{
		int mn = INF;
		int mnIdx = parent;
		for(int i = 1; i <= v; ++i) // 부모가 parent인 i번째 정점이거나 자신이 parent
		{
			int mx = -INF;
			if(Find(i) == parent)
			{
				for(int j = 1; j <= v; ++j) // 그 정점과 연결된 j번째 정점 
				{
					if (j == i || floyd[i][j] == INF) continue;
					if(mx < floyd[i][j])
						mx = floyd[i][j];
				}
			}

			if(mx != -INF && mn > mx)
			{
				mn = mx;
				mnIdx = i;
			}
		}
		leaders.push_back(mnIdx);
	}

	sort(leaders.begin(), leaders.end());

	for(auto leader : leaders)
		cout << leader << "\n";

	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :
