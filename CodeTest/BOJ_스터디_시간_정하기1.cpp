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

// 투 포인터 방식 -> 인덱스 10만번 * 사람 수 10만 시간 초과
// 각 구간의 되는 사람의 합을 미리 구해놓는다면?

int main()
{
	fastio;

	int N, T;
	cin >> N >> T;

	vector<int> Times(100'001, 0);
	for(int i = 1; i <= N; i++)
	{
		int cnt;
		cin >> cnt;
		for (int k = 0; k < cnt; ++k)
		{
			int s, d;
			cin >> s >> d;
			Times[s]++;
			Times[d]--;
		}
	}

	for(int i = 1; i <= 100'000; ++i)
	{
		Times[i] += Times[i - 1];
	}

	vector<ll> acc(100'001, 0);
	acc[0] = Times[0];
	for(int i = 1; i <= 100'000; i++)
	{
		acc[i] = acc[i - 1] + Times[i];
	}

	ll Max = -1;
	int idx = -1;
	for(int i = 0; i <= 100'000 - T; ++i)
	{
		ll val;
		if (i == 0)
			val = acc[i + T - 1];
		else 
			val = acc[i + T - 1] - acc[i-1];

		if(Max < val)
		{
			Max = val;
			idx = i;
		}
	}

	cout << idx << " " << idx + T;

	return 0;
}


// S : 9:34
// U : 9:36
// T : 
// C :
// Total :