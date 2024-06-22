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
#include <set>
#include <string>
#include <memory.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

// 싸이클이 있는 위상정렬

int main()
{
	fastio;

	int n, m;
	cin >> n >> m;

	vector<vector<bool>> adjMat(n + 1, vector<bool>(n + 1, false));
	vector<vector<int>> adjList(n + 1);
	vector<int> arrowCnt(n + 1, 0);
	for(int i = 0; i < m; ++i)
	{
		int cnt;
		cin >> cnt;
		int a, b;
		cin >> a;
		for(int j = 1; j < cnt; ++j)
		{
			cin >> b;
			if (!adjMat[a][b])
			{
				adjList[a].push_back(b);
				arrowCnt[b]++;
				adjMat[a][b] = true;
			}
			a = b;
		}
	}

	vector<int> ans;
	queue<int> Q;
	vector<bool> visited(n + 1, false);
	for (int i = 1; i < arrowCnt.size(); ++i)
		if (arrowCnt[i] == 0)
		{
			Q.push(i);
			visited[i] = true;
			ans.push_back(i);
		}

	while(!Q.empty())
	{
		auto front = Q.front();
		Q.pop();

		for(auto nxt : adjList[front])
		{
			if (visited[nxt])
			{
				cout << 0;
				return 0;
			}

			arrowCnt[nxt]--;
			if (arrowCnt[nxt] == 0)
			{
				visited[nxt] = true;
				ans.push_back(nxt);
				Q.push(nxt);
			}
		}
	}

	 // 여기 조건을 조심.. 
	if (ans.size() == n)
		for (auto it : ans)
			cout << it << "\n";
	else
		cout << 0;
	
		


	return 0;
}


// S : 611
// U : 
// T : 
// C :
// Total :