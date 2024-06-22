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

// 도착지가 가장 시작과 가까운 애들 나올때마다 돌아감.
// 다음과 겹쳐야 함.

int main()
{
	fastio;
	int n, m;
	cin >> n >> m;
	vector<pii> guests;
	ll ans = 0;
	for(int i = 0; i < n ;++i)
	{
		int s, e;
		cin >> s >> e;
		if( s > e)
			guests.push_back({ e,s });
	}

	sort(guests.begin(), guests.end());

	int cur = 0;

	for(int i = 0; i < guests.size(); ++i)
	{
		int e = guests[i].first;
		int s = guests[i].second;

		while (i + 1 < guests.size() &&  guests[i+1].first <= s )
		{
			s = max(guests[i + 1].second, s);
			++i;
		}

		ans += (s - cur) + (s - e);
		cur = e;
	}

	ans += m - cur;
	cout << ans;

	return 0;
}


// S : 927
// U : 
// T : 
// C :
// Total :