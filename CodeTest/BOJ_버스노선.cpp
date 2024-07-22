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

// 도로 길이 10억
// 개수 50만 -> n^2으로는 안됨.

// 직선 기준 - n 풀이
// 1. 시작점으로 sort
// 2. 다음과 완전히 겹친다 -> 그 노선 빼고 다음 노선으로
// 3. 아니다 -> 다음 노선을 기준으로 2로.

// 원이어서 문제가 된다.
// 확장!

struct tInfo
{
	int s;
	int e;
	int idx;

	bool operator<(const tInfo& rhs) const
	{
		if (s == rhs.s)
			return e > rhs.e;
		return s < rhs.s;
	}
};

int main()
{
	fastio;

	int n, m;
	cin >> n >> m;

	vector<tInfo> infos;
	for(int i = 0; i < m; ++i)
	{
		int s, e;
		cin >> s >> e;
		if (e == 0) e = n;
		if( s < e)
		{
			infos.push_back({ s, e, i });
			infos.push_back({ s + n, e + n, i }); // 원점에 걸치지 않는 노선을 걸치는 노선이 이해할 수 있도록 확장.
		}
		else
		{
			infos.push_back({ s, e + n, i });
		}
	}

	sort(infos.begin(), infos.end());

	vector<bool> ans(m, true);
	auto cur = infos.front();
	for(int i = 1; i < infos.size(); ++i)
	{
		if (cur.e >= infos[i].e)
			ans[infos[i].idx] = false;
		else
			cur = infos[i];
	}

	for (int i = 0; i < m; ++i)
		if (ans[i])
			cout << i + 1 << " ";

	return 0;
}

// S : 5 04
// U : 5 06
// T : 5 18
// C : 5 40
// Total : 36min

// Comment
// 구간을 맨 처음에는 7 ~ 2 같은 경우에 7 - 10 & 0 - 2로 나누어서 풀려고 했는데, 이러면 복잡해진다.
// 확장을 통해서 O(2*n) = O(n) 풀이로 해결할 수 있다.

 