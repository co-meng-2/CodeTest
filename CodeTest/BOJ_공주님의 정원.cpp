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

// 앞의 범위를 포함하거나 1만큼 더 크면서 가장 큰 범위를 넣으면 된다.

int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main()
{
	fastio;

	int n;
	cin >> n;

	vector<pii> flowers(n);


	for(int i = 0; i < n; ++i)
	{
		int m, d;
		cin >> m >> d;

		while(m--)
			d += days[m];
		flowers[i].first = d;
		cin >> m >> d;
		while (m--)
			d += days[m];
		flowers[i].second = d;
	}

	sort(flowers.begin(), flowers.end());

	int s = 60;
	int e = 334;
	int cnt = 0;
	int curIdx = 0;

	while (s <= e)
	{
		int ns = s;
		while (curIdx < n && flowers[curIdx].first <= s)
		{
			ns = max(ns, flowers[curIdx].second);
			curIdx++;
		}
		if (ns != s)
		{
			s = ns;
			cnt++;
		}
		else
			break;
	}

	if (s <= e)
		cout << 0;
	else
		cout << cnt;

	return 0;
}
