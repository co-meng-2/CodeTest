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
using namespace std;

using ll = long long;
using pii = pair<int, int>;

// 받는 쪽의 간선이 있는 정점에 대해서 사이클이 만들어 질 수 있다.

int main()
{
	fastio;
	int T;
	cin >> T;

	while(T--)
	{
		int n;
		cin >> n;
		vector<int> arrow(n);
		for (int i = 0; i < n; ++i)
			cin >> arrow[i];
		vector<vector<int>> rarrow(n);
		for (int i = 0; i < n; ++i)
			rarrow[arrow[i] - 1].push_back(i);

		vector<bool> visited(n, false);
		int sum = 0;
		for(int i = 0; i < n; ++i)
		{
			if (visited[i]) continue;
			queue<pii> Q;
			Q.push({i, 1});
			visited[i] = true;
			while(!Q.empty())
			{
				auto [cur, cnt] = Q.front();
				Q.pop();

				for(auto nxt : rarrow[cur])
				{
					if (nxt == i) sum += cnt;
					if (visited[nxt]) continue;
					visited[nxt] = true;

					Q.push({ nxt, cnt + 1 });
				}
			}
		}
		cout << n - sum << "\n";
	}

	return 0;
}


// S : 545
// U : 
// T : 
// C :
// Total :