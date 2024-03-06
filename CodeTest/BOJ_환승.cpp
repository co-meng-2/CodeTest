#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>
#include <queue>

using pii = std::pair<int, int>;
// hyper 묶음으로 생각
// 같은 hyper에 있다 -> 거리 + 1로 넣어줌.
// [hyper][v] [v][hyper] 2개를 만들어줌.
// 

int main()
{
	fastio;

	int v, cnt, hyper;
	cin >> v >> cnt >> hyper;

	vector<vector<int>> vh(v + 1);
	vector<vector<int>> hv(hyper + 1);
	for (int i = 1; i <= hyper; ++i)
	{
		for (int j = 0; j < cnt; ++j)
		{
			int input;
			cin >> input;
			vh[input].push_back(i);
			hv[i].push_back(input);
		}
	}

	vector<bool> visited(hyper + 1, false);
	std::queue<pii> Q;
	Q.push({ 1, 1});
	int ans = -1;
	while(!Q.empty())
	{
		auto [cur, w] = Q.front();
		Q.pop();
		if (cur == v)
		{
			ans = w;
			break;
		}
			
		for(auto ch : vh[cur])
		{
			if (visited[ch]) continue;
			visited[ch] = true;
			for(auto nv : hv[ch])
			{
				Q.push({ nv, w + 1 });
			}
		}
	}

	cout << ans;

	return 0;
}


// S :
// U :
// T :
// C :
// Total :