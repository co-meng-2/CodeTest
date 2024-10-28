#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

int popcount(unsigned int n) {
	n = (n >> 1 & 0x55555555) + (n & 0x55555555);
	n = (n >> 2 & 0x33333333) + (n & 0x33333333);
	n = (n >> 4 & 0x0F0F0F0F) + (n & 0x0F0F0F0F);
	n = (n >> 8 & 0x00FF00FF) + (n & 0x00FF00FF);
	n = (n >> 16 & 0x0000FFFF) + (n & 0x0000FFFF);
	return n;
}

unsigned int Calc (char  c)
{
	int sub = 0;
	if (c > 'a')
		++sub;
	if (c > 'c')
		++sub;
	if (c > 'i')
		++sub;
	if (c > 'n')
		++sub;
	if (c > 't')
		++sub;
	return c - 'a' - sub;
};

int n, m;

int main()
{
	fastio;

	cin >> n >> m;
	vector<unsigned int> bits(n);
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;

		for (auto c : str)
		{
			if (c == 'a' || c == 'n' || c == 't' || c == 'i' || c == 'c') continue;
			bits[i] |= (1 << Calc(c)); 
		}
	}

	int ans = 0;
	for (unsigned int i = 0; i < (1 << 21); ++i)
	{
		if (popcount(i) == m - 5)
		{
			int ret = 0;
			for (auto bit : bits)
			{
				if ((bit & i) == bit)
					++ret;
			}
			ans = max(ret, ans);
		}
	}

	cout << ans;

	return 0;
}


// S : 550
// U : 
// T : 
// C : 608 시간초과
// Total :
