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

// 위상 정렬
// 선행 현재 작업까지 걸리는 시간, 현재 작업 으로 큐에 넣어줌

int main()
{
	fastio;

	int n;
	cin >> n;

	vector<vector<int>> adjList(n + 1);
	vector<int> times(n + 1);
	vector<int> degree(n + 1);
	for(int i = 1; i <= n; ++i)
	{
		int w;
		int m;
		cin >> w >> m;
		times[i] = w;
		for(int j = 0; j < m; ++j)
		{
			int pre;
			cin >> pre;
			degree[i]++;
			adjList[pre].push_back(i);
		}
	}

	priority_queue<pii, vector<pii>, greater<>> PQ;
	for(int i = 1; i <=n; ++i)
	{
		if (!degree[i])
			PQ.push({times[i], i});
	}

	while(true)
	{
		auto [ctime, cur] = PQ.top();
		PQ.pop();

		for(auto nxt : adjList[cur])
		{
			degree[nxt]--;
			if (!degree[nxt])
				PQ.push({ ctime + times[nxt] ,nxt});
		}

		if(PQ.empty())
		{
			cout << ctime;
			break;
		}
	}

	return 0;
}


// S : 10 42
// U : 10 43
// T : 10 46
// C : 10 54
// Total : 12min
