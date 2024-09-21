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

// 1. 벨트 회전
// 2. 벨트 올라간 순서대로 움직일 수 있다면 한 칸씩 움직임
// 3. 올릴 수 있다면 로봇 올림
// 4. K판정

int n, k;

int main()
{
	fastio;
	
	cin >> n >> k;
	deque<pii> belt(2 * n);
	for(int i = 0; i < 2 * n; ++i)
	{
		cin >> belt[i].first;
	}

	queue<int> Q;

	int step = 0;
	while (k > 0)
	{
		step++;
		auto tmp = belt.back();
		belt.pop_back();
		belt.push_front(tmp);
		belt[n - 1].second = false;

		int qsz = Q.size();
		while(qsz--)
		{
			auto cur = Q.front();
			Q.pop();

			++cur;
			if (cur == n - 1) continue;
			int nxt = cur + 1;

			if (belt[nxt].second || belt[nxt].first == 0)
				Q.push(cur);
			else
			{
				belt[cur].second = false;
				if (nxt != n - 1)
				{
					belt[nxt].second = true;
					Q.push(nxt);
				}
				belt[nxt].first--;
				if (belt[nxt].first == 0)
					k--;
			}
		}

		if (belt[0].second == false && belt[0].first)
		{
			belt[0].first--;
			if (belt[0].first == 0)
				k--;
			belt[0].second = true;
			Q.push(0);
		}
	}

	cout << step;

	return 0;
}


// S : 1 35
// U : 
// T : 
// C :
// Total :
