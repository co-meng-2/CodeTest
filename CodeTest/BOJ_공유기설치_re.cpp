#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

// 10억 거리 -> 대충 이분탐색 써야함
// 최대 거리를 mid라고 하면 TTTTTFFFFFF이런식으로 나올 것
// 1 + (n-1)*mid가 10억을 초과하지 않으면 T로 조건을 잡으면 될듯?
// 근데 집의 좌표가 고정되어 있음
// 그렇다면 거리에 따라서 항상 TTTFF이런식으로 나오나?
// 1 2 4 8 9 에서 3개가 있을 떄 최적은 1 5 9 로 4이지만 사실은 1 4 9로 3이다.
// 그러면 가장 작은 위치부터 시작해서 다음 위치로 뛰면서 거리보다 같거나 큰채로 모든 공유기를 쓰면 true로 하면 되지 않을까?

bool check(int C ,int dist, vector<int>& locations)
{
	int s = 0;
	int d = 1;
	while (true)
	{
		if (d >= locations.size())
			return false;

		if (locations[d] - locations[s] >= dist)
		{
			s = d;
			d++;
			C--;
			if (C == 0)
				return true;
		}
		else
		{
			d++;
		}
	}
}

int main()
{
	fastio;

	int N, C;
	cin >> N >> C;

	vector<int> locations(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> locations[i];
	}
	std::sort(locations.begin(), locations.end());
	
	// BAD
	// int lo = locations.front();
	// int hi = locations.back() + 1;
	// lo = 5000 hi = 5004의 경우를 생각해보자
	
	int lo = 1;
	int hi = locations.back() - locations.front() + 1;

	while (lo + 1 < hi)
	{
		int mid = (lo + hi) / 2;
		
		if (check(C - 1, mid, locations))
			lo = mid;
		else
			hi = mid;
	}

	cout << lo;

	return 0;
}


// S : 2:09
// U : 2:11
// T : 2:23
// C : 2:51
// Total :