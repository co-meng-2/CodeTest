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
#include <memory.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

// 별똥별이 떨어지는 한 곳을 시작점으로 그 점을 LT, LB, RT, RB로 생각한다.
// 별똥별이 최대 100개이므로 점들이 포함되어 있는지 판단한다.
// O
// 100 * 4 * 100 = 40000
// 하지만 이 방법 안될듯 ? 사각형 중점마다 별똥별이 있는 경우 생각.

// 그러면 두 별똥별을 뽑아 하나의 y 하나의 x 를 시작점으로 시작하면 되지 않을까?

int main()
{
	fastio;

	// 그냥 y,x 바꿔서 생각
	int n, m, l, k;
	cin >> n >> m>> l >> k;

	vector<pii> stars(k);
	for (int i = 0; i < k; ++i)
		cin >> stars[i].first >> stars[i].second;

	int mx = 0;
	for(int i = 0; i < k; ++i)
	{
		for(int j = 0; j < k; ++j)
		{
			int sy = stars[i].first;
			int sx = stars[j].second;

			int ey = sy + l;
			int ex = sx + l;

			int ans = 0;
			for (auto [stary, starx] : stars)
			{
				if (sy <= stary && stary <= ey && sx <= starx && starx <= ex)
					++ans;
			}
			mx = max(ans, mx);
		}
	}

	cout << k - mx;

	return 0;
}


// S : 9 16
// U : 9 17
// T : 
// C :
// Total :
