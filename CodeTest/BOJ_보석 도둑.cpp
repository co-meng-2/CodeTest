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

int main()
{
	fastio;

	int jcnt, bcnt;
	cin >> jcnt >> bcnt;

	// 무게 가격
	vector<pii> jewels(jcnt);
	for(int i = 0; i < jcnt; ++i)
		cin >> jewels[i].first >> jewels[i].second;
	sort(jewels.begin(), jewels.end());

	vector<int> bags(bcnt);
	for (int i = 0; i < bcnt; ++i)
		cin >> bags[i];
	sort(bags.begin(), bags.end());

	// 최대가 되기 위해서는 작은 크기이면서 가장 가치가 큰 애들을 넣어야 함
	//  a < b < c

	priority_queue<int> PQ;
	int jIdx = 0;
	ll ans = 0;
	for(auto bag : bags)
	{
		while(jIdx < jcnt && jewels[jIdx].first <= bag)
		{
			PQ.push(jewels[jIdx].second);
			jIdx++;
		}

		if(!PQ.empty())
		{
			auto top = PQ.top();
			PQ.pop();

			ans += top;
		}
	}

	cout << ans;

	return 0;
}


// S : 609
// U : 
// T : 
// C :
// Total :