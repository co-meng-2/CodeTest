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
using pll = pair<ll, ll>;
using tiii = tuple<int, int, int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

int ccw(pll v1, pll v2, pll v3)
{
	pll vec1 = { v2.first - v1.first, v2.second - v1.second }; // {1, 1}
	pll vec2 = { v3.first - v2.first, v3.second - v2.second }; // {0, -1}
	ll ret = vec1.first * vec2.second - vec2.first * vec1.second;

	if (ret < 0)
		return -1;
	else if (ret > 0)
		return 1;

	return 0;
}

int main()
{
	fastio;

	pll v1, v2, v3, v4;
	cin >> v1.first >> v1.second >> v2.first >> v2.second;
	cin >> v3.first >> v3.second >> v4.first >> v4.second;

	int ret1 = ccw(v1, v2, v3);
	int ret2 = ccw(v1, v2, v4);
	int ret3 = ccw(v3, v4, v1);
	int ret4 = ccw(v3, v4, v2);

	if (ret1 == 0 &&  ret2 == 0 && ret3 == 0 && ret4 == 0)
	{
		if (v1.first > v2.first)
			swap(v1.first, v2.first);
		if (v3.first > v4.first)
			swap(v3.first, v4.first);

		bool bx = (v1.first <= v4.first) && (v2.first >= v3.first);

		if (v1.second > v2.second)
			swap(v1.second, v2.second);
		if(v3.second > v4.second)
			swap(v3.second, v4.second);

		bool by = (v1.second <= v4.second) && (v2.second >= v3.second);

		if (bx && by)
			cout << 1;
		else
			cout << 0;
	}
	else
	{
		if (ret1 * ret2 <= 0 && ret3 * ret4 <= 0)
			cout << 1;
		else
			cout << 0;
	}

	return 0;
}