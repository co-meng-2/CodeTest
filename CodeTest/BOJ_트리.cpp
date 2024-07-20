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

// root L ...... R ......
// [L] / root / [R]

void dfs(int& preIdx, int s, int e, vector<pii>& tree, vector<int>& pre, vector<int>& inIdxs)
{
	if (preIdx == pre.size()) return;

	int curNum = pre[preIdx];
	int inIdx = inIdxs[curNum];

	if (s < inIdx)
	{
		tree[curNum].first = pre[preIdx++];
		dfs(preIdx, s, inIdx - 1, tree, pre, inIdxs);
	}

	if (inIdx < e)
	{
		tree[curNum].second = pre[preIdx++];
		dfs(preIdx, inIdx + 1, e, tree, pre, inIdxs);
	}

	cout << curNum << " ";
}

int T;

int main()
{
	fastio;

	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		vector<pii> tree(n+1);
		vector<int> pre(n);
		vector<int> preIdx(n+1);
		vector<int> in(n);
		vector<int> inIdxs(n+1);
		for (int i = 0; i < n; ++i)
		{
			cin >> pre[i];
			preIdx[pre[i]] = i;
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> in[i];
			inIdxs[in[i]] = i;
		}

		int idx = 0;
		dfs(idx, 0, n - 1, tree, pre, inIdxs);
		cout << "\n";
	}

	return 0;
}


// S : 9 32
// U : 9 32
// T : 
// C :
// Total :
