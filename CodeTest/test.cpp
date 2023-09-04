#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <map>

using std::deque;
using std::queue;
using std::vector;
using std::pair;
using std::priority_queue;
using std::map;

using std::cout;
using std::cin;
using std::make_pair;
using std::abs;
using std::fill;
using std::max;
using std::min;
using std::swap;

typedef long long ll;
typedef pair<int, int> P;

int sg[2'000'001]{};
int m;
int a, b, c;

void ChangeElem(int _flavor, int _cnt)
{
	int idx = 1;
	sg[idx] += _cnt;

	int hi = 1'000'000;
	int lo = 1;

	while(lo + 1 < hi)
	{
		int mid = (lo + hi) / 2;
		if (_flavor <= mid)
		{
			hi = mid;
			idx *= 2;
		}
		else
		{
			lo = mid;
			idx *= 2 + 1;
		}
		sg[idx] += _cnt;
	}
}

// 원하는 숫자의 sg에서의 말단 인덱스를 찾음.
int FindIdx(int _findIdx)
{
	int hi = 1'000'000;
	int lo = 1;

	while (lo + 1 < hi)
	{
		int mid = (lo + hi) / 2;
		if (_findIdx <= mid)
		{
			hi = mid;
		}
		else
		{
			lo = mid;
		}
	}

	return lo;
}

int GetSum(int _order, int s = 1, int e = 1'000'000, int idx = 1, int sum = 0 )
{
	// s는 고정
	while(sg[idx] > _order)
	{
		int mid = (s + e) / 2;
		e = mid;

		idx *= 2;
	}

	if (sg[idx] == _order)
		return e;

	GetSum(_order, e + 1, )

	
}



int main()
{
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	cin >> m;
	for(int i = 0; i < m; ++ i)
	{
		cin >> a;
		if(a == 1)
		{
			cin >> b;

		}
		else // add candy
		{
			cin >> b >> c;
			ChangeElem(b, c);
		}
	}


	return 0;
}