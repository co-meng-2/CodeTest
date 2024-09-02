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


int main()
{
	fastio;

	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;

		priority_queue<int> PQ_Dec;
		priority_queue<int, vector<int>, greater<>> PQ_Inc;

		int num;
		cin >> num;
		PQ_Dec.push(num);
		vector<int> ans;
		ans.push_back(num);
		for(int i = 1; i < n; ++i)
		{
			cin >> num;

			if (num <= PQ_Dec.top())
				PQ_Dec.push(num);
			else
				PQ_Inc.push(num);

			if(PQ_Dec.size() >= PQ_Inc.size() + 2)
			{
				PQ_Inc.push(PQ_Dec.top());
				PQ_Dec.pop();
			}

			if(PQ_Inc.size() == PQ_Dec.size())
			{
				PQ_Dec.push(PQ_Inc.top());
				PQ_Inc.pop();
			}

			if (i % 2 == 0)
				ans.push_back(PQ_Dec.top());
		}


		cout << n / 2 + 1 << "\n";
		for (int i = 0; i < ans.size(); ++i)
		{
			cout << ans[i] << " ";

			if (i % 10 == 9)
				cout << "\n";
		}
			
		cout << "\n";
	}

	return 0;
}


// S : 1:03
// U : 1:04
// T : 1:45
// C : 2:00
// Total :
