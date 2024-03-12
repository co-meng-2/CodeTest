#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

// 15, 13, 11,3, / 7 6 5 4 3 2 1
// 33 429 6500 * 15

// 집합의 사전 순 처음 생각해봄.

struct tInfo
{
	int a, b, c, d, w;
	vector<int> idxs;

	void operator+=(const tInfo& _rhs)
	{
		a += _rhs.a;
		b += _rhs.b;
		c += _rhs.c;
		d += _rhs.d;
		w += _rhs.w;
	}

	bool operator<(const tInfo& _rhs)
	{
		int i = 0;
		while(true)
		{
			if (i == idxs.size()) return true;
			else if (i == _rhs.idxs.size()) return false;

			if (idxs[i] < _rhs.idxs[i]) return true;
			else if (idxs[i] > _rhs.idxs[i]) return false;
			i++;
		}
	}
};

int main()
{
	fastio;

	int n;
	cin >> n;

	tInfo target;
	cin >> target.a >> target.b >> target.c >> target.d;

	vector<tInfo> items(n);
	for (auto& item : items)
	{
		cin >> item.a >> item.b >> item.c >> item.d >> item.w;
	}

	tInfo ans{};
	const int INF = 1000000000;
	ans.w = INF;
	for (int i = 1; i <= (1 << n) - 1; ++i)
	{
		vector<int> sels;
		for (int j = 0; j < n; ++j)
		{
			if (i & (1 << j))
				sels.push_back(j);
		}

		tInfo total{};
		for (auto sel : sels)
		{
			total += items[sel];
			total.idxs.push_back(sel);
		}
		if (target.a <= total.a && target.b <= total.b && target.c <= total.c && target.d <= total.d)
		{
			if(total.w < ans.w)
				ans = total;
			else if(total.w == ans.w)
			{
				if (total < ans)
					ans = total;
			}
		}
	}

	if (ans.idxs.empty())
		cout << -1;
	else
	{
		cout << ans.w << "\n";
		for (auto idx : ans.idxs)
			cout << idx + 1 << " ";
	}

	return 0;
}


// S : 12:29
// U : 12:29
// T : 12:36
// C : 1:30
// Total : 1h