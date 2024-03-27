#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;


bool Move(int com, ll dx, ll& s, ll& e, int& mx)
{
	if (com % 2) // +
	{
		if (e == mx)
		{
			s = max(s - dx, 0LL);
		}
		else
		{
			s -= dx;
			s = max(s, 0LL);
			e -= dx;
			if (e < 1)
			{
				return false;
			}
		}

	}
	else // -
	{
		if (s == 0)
		{
			e = min(e + dx, (ll)mx);
		}
		else
		{
			s += dx;
			if (s > mx - 1)
			{
				return false;
			}
			e += dx;
			e = min(e, (ll)mx);
		}
	}

	return true;
}

long long solution(int n, int m, int x, int y, vector<vector<int>> queries)
{

	// y,x 로부터 역계산?
	// 되는 범위로 생각을하자

	// n행 m열
	// x행 y열

	ll ys = x;
	ll ye = x + 1;
	ll xs = y;
	ll xe = y + 1;

	for (auto it = queries.rbegin(); it != queries.rend(); ++it)
	{
		int com = it->at(0);
		ll dx = it->at(1);

		if(com <= 1)
		{
			if (Move(com, dx, xs, xe, m) == false)
				return 0;
		}
		else
		{
			if (Move(com, dx, ys, ye, n) == false)
				return 0;
		}
	}

	
	return (ye - ys) * (xe - xs);
}

int main()
{
	int n, m, x, y, k;
	cin >> n >> m >> x >> y >> k;

	vector<vector<int>> queries(k);
	for (int i = 0; i < k; ++i)
	{
		int com, dx;
		cin >> com >> dx;
		queries[i].push_back(com);
		queries[i].push_back(dx);
	}

	cout << solution(n, m, x, y, queries);

	return 0;
}