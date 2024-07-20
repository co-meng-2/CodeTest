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

// dp로 나눠서 풀면 될듯
// 아니 제한이 10만이었네; -> 배열 말고 pii set로 변경!

set<pii> memo;

int asz, bsz, armn, brmn;

int main()
{
	fastio;

	cin >> asz >> bsz >> armn >> brmn;

	queue<pii> Q;
	Q.push({ 0,0 });
	memo.insert({ 0,0 });

	int cnt = 0;
	int ans = -1;
	while(!Q.empty())
	{
		if (memo.count({ armn, brmn })) // 0부터 시작
		{
			ans = cnt;
			break;
		}

		int qsz = Q.size();
		cnt++;
		while (qsz--)
		{
			auto [ca, cb] = Q.front();
			Q.pop();

			for (auto [na, nb] : { pii{asz, cb}, pii{ca, bsz}, pii{0, cb}, pii{ca, 0}, pii{min(ca + cb, asz), max(ca + cb - asz, 0)}, pii{max(ca + cb - bsz, 0), min(ca + cb, bsz)}})
			{
				if (!memo.count({na, nb}))
				{
					memo.insert({ na,nb });
					Q.push({ na, nb });
				}
			}
		}
	}

	cout << ans;

	return 0;
}


// S : 709
// U : 710
// T : 710
// C : 722
// Total : 13min
