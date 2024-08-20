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

int n;
vector<int> times;
vector<vector<int>> c;

void dfs(int cur = 0)
{
	for(auto child : c[cur])
		dfs(child);

	sort(c[cur].begin(), c[cur].end(), [&](const int& lhs, const int& rhs)->bool {return times[lhs] > times[rhs]; });

	int add = 1;
	for (auto child : c[cur])
	{
		times[cur] = max(add + times[child], times[cur]);
		add++;
	}
}

int main()
{
	fastio;
	cin >> n;

	times.resize(n);
	c.resize(n);

	for (int i = 0; i < n; ++i)
	{
		int p;
		cin >> p;
		if(p != -1)
			c[p].push_back(i);
	}

	dfs();

	cout << times[0];

	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :
