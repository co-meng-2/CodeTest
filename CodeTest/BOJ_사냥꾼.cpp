#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

// L = |x - a| + b
// x = a - b + L
// x = a + b - L
// x  <= a+-(L-b)
// a+b-L <= x <= a-b+L

// 이분탐색으로  a <= x <= b 이런 조건을 구해야 할 때 어떻게 해야 되는지 생각해보자.
// 단순히 이분탐색을 2번 수행하는 방식으로는 이 범위를 구할 수 있고
// 만약 저 범위에 한 번만 포함되는 것을 구하고 싶다면 한 번으로도 수행할 수 있다.

struct tPos
{
	int y;
	int x;
};



int main()
{
	fastio;

	int M, N, L;
	cin >> M >> N >> L;

	vector<int> loc(M + 1);
	for (int i = 1; i <= M; ++i)
		cin >> loc[i];
	std::sort(loc.begin(), loc.end());

	vector<tPos> animals;
	for (int i = 0; i < N; ++i)
	{
		int x, y;
		cin >> x >> y;
		if (y > L) continue;
		animals.push_back({ y,x });
	}

	int ans = 0;
	for(auto animal : animals)
	{
		int val1 = animal.x + animal.y - L;
		int val2 = animal.x - animal.y + L;
		int min = std::min(val1, val2);
		int max = std::max(val1, val2);

		int lo = 1;
		int hi = loc.size() - 1;
		while(lo <= hi)
		{
			int mid = (lo + hi) / 2;
			if (min <= loc[mid] && loc[mid] <= max)
			{
				ans++;
				break;
			}
			else if (loc[mid] < min)
				lo = mid + 1;
			else if (loc[mid] > max)
				hi = mid - 1;
		}
	}

	cout << ans;

	return 0;
}

// S : 9:16
// U : 9:19
// T : 9:42
// C :
// Total :