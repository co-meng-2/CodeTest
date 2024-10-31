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

int main()
{
	fastio;

	int n;
	cin >> n;
	vector<pii> infos(n);
	priority_queue<int, vector<int>, greater<>> wait;
	priority_queue<pii, vector<pii>, greater<>> seat;
	for (int i = 0; i < n; ++i)
	{
		int s, e;
		cin >> s >> e;
		infos[i] = { s, e };
		wait.push(i);
	}

	sort(infos.begin(), infos.end());

	vector<int> cnts;

	for (int i = 0; i < n; ++i)
	{
		while(!seat.empty() && seat.top().first < infos[i].first)
		{
			wait.push(seat.top().second);
			seat.pop();
		}

		auto idx = wait.top();
		wait.pop();
		seat.push({infos[i].second, idx});
		if(idx == cnts.size())
		{
			cnts.push_back(1);
		}
		else
		{
			++cnts[idx];
		}
	}

	cout << cnts.size() << "\n";
	for (auto elem : cnts)
	{
		cout << elem << " ";
	}

	return 0;
}


// S : 1117
// U : 1118
// T : 1119
// C : 1132
// Total : 15min
