#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

int T;
int n;

int main()
{
	fastio;

	cin >> T;
	while(T--)
	{
		cin >> n;
		
		vector<pii> locs(n + 2);
		for(int i = 0; i < n + 2; ++i)
		{
			cin >> locs[i].first >> locs[i].second;
		}


		vector<bool> visited(n + 2);
		queue<pii> Q;
		Q.push(locs.front());
		visited[0] = true;
		while(!Q.empty())
		{
			auto [cy, cx] = Q.front();
			Q.pop();

			for(int i = 0; i < n + 2; ++i)
			{
				if (visited[i]) continue;
				auto [ny, nx] = locs[i];
				if (abs(ny - cy) + abs(nx - cx) > 1000) continue;
				visited[i] = true;
				Q.push({ ny, nx });
			}
		}
		if (visited[n + 1])
			cout << "happy" << "\n";
		else
			cout << "sad" << "\n";
	}

	return 0;
}


// S : 4 35
// U : 4 37
// T : 4 38
// C : 4 46
// Total : 11min
