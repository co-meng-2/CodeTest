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

vector<int> infos[1001]{};

int main()
{
	fastio;

	int n;
	cin >> n;

	int MxDay = 0;
	for(int i = 0; i < n; ++i)
	{
		int d, w;
		cin >> d >> w;
		infos[d].push_back(w);
		MxDay = max(d, MxDay);
	}

	int sum = 0;
	priority_queue<int> PQ;
	for(int day = MxDay; day > 0; --day)
	{
		for (int i = 0; i < infos[day].size(); ++i)
			PQ.push(infos[day][i]);

		if (!PQ.empty())
		{
			sum += PQ.top();
			PQ.pop();
		}
	}

	cout << sum;

	return 0;
}


// S : 2 37
// U : 2 38
// T : 2 39
// C : 2 48
// Total : 11min
