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


int main()
{
	fastio;

	int T;
	cin >> T;

	while(T--)
	{
		int n;
		cin >> n;

		bool valid = true;
		vector<int> ori(n + 1);
		vector<int> oriIdx(n + 1);
		vector<vector<bool>> adjMat(n + 1, vector<bool>(n + 1));
		vector<int> degree(n + 1);
		for (int i = 1; i <= n; ++i)
		{
			cin >> ori[i];
			oriIdx[ori[i]] = i;
		}

		for(int i = 1; i <=n; ++i)
			for(int j = i + 1; j <=n; ++j)
			{
				if (oriIdx[i] < oriIdx[j])
				{
					adjMat[i][j] = true;
					degree[j]++;
				}
				else
				{
					adjMat[j][i] = true;
					degree[i]++;
				}
			}

		int m;
		cin >> m;

		vector<bool> changed(n + 1);
		
		for(int i = 0; i < m ; ++i)
		{
			int a, b;
			cin >> a >> b;

			if(oriIdx[a] < oriIdx[b])
			{
				adjMat[b][a] = true;
				degree[a]++;
				adjMat[a][b] = false;
				degree[b]--;
			}
			else
			{
				adjMat[a][b] = true;
				degree[b]++;
				adjMat[b][a] = false;
				degree[a]--;
			}
		}

		if(!valid)
		{
			cout << "IMPOSSIBLE\n";
			continue;
		}

		priority_queue<pii, vector<pii>, greater<>> PQ;

		valid = false;
		for(int i = 1; i <=n; ++i)
		{
			if (degree[i] == 0)
			{
				valid = true;
				PQ.push({ 0, i });
			}
		}

		vector<int> ans;
		while(!PQ.empty())
		{
			auto [cw, cur] = PQ.top();
			PQ.pop();

			ans.push_back(cur);

			for(int i = 1; i <=n; ++i)
			{
				if (!adjMat[cur][i]) continue;
				degree[i]--;
				if(degree[i] == 0)
					PQ.push({degree[i], i});
			}
		}

		if (ans.size() != n)
			valid = false;

		if (!valid)
		{
			cout << "IMPOSSIBLE\n";
			continue;
		}

		for(auto it : ans)
		{
			cout << it << " ";
		}
		cout << "\n";
	}


	return 0;
}


// S : 1 10
// U : 1 11
// T : 1 19
// C :
// Total :
