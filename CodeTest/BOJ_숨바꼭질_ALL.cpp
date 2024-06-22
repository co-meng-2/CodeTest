#include <iostream>
#include <numeric>
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
#include <memory.h>
#include <cmath>
#include "MyDebug.h"
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiil = tuple<int, int, ll, ll>;

const int INF = 0x3f3f3f3f;

int memo[500001]{};
int s, d;

void solution3()
{
	memset(memo, 0x3f, sizeof(memo));
	cin >> s >> d;

	queue<pii> Q;
	Q.push({ 0, s });
	memo[s] = 0;

	while (!Q.empty())
	{
		auto [cnt, cur] = Q.front();
		Q.pop();

		int nxt = cur * 2;
		while (nxt > 0 && nxt <= 100000 && memo[nxt] > cnt)
		{
			memo[nxt] = cnt;
			Q.push({ cnt, nxt });
			nxt *= 2;
		}

		if (cur - 1 >= 0 && memo[cur - 1] > cnt + 1)
		{
			memo[cur - 1] = cnt + 1;
			Q.push({ cnt + 1, cur - 1 });
		}
		if (cur + 1 <= 100000 && memo[cur + 1] > cnt + 1)
		{
			memo[cur + 1] = cnt + 1;
			Q.push({ cnt + 1, cur + 1 });
		}
	}

	cout << memo[d];
}

void solution4()
{
	memset(memo, -1, sizeof(memo));
	cin >> s >> d;

	if(s >= d)
	{
		cout << s - d << "\n";
		for (int i = s; i >= d; --i)
			cout << i << " ";
		return;
	}

	queue<pii> Q;
	Q.push({0, s});
	memo[s] = INF;
	while(!Q.empty())
	{
		auto [cnt, cur] = Q.front();
		Q.pop();

		if(cur == d)
		{
			cout << cnt << "\n";
			vector<int> ans;
			while(cur != INF)
			{
				ans.push_back(cur);
				cur = memo[cur];
			}

			for(auto it = ans.rbegin(); it != ans.rend(); ++it)
			{
				cout << *it << " ";
			}
			break;
		}

		if (cur - 1 >= 0 && memo[cur - 1] < 0)
		{
			memo[cur - 1] = cur;
			Q.push({ cnt + 1, cur - 1 });
		}
		if (cur + 1 <= 100000 && memo[cur + 1] < 0)
		{
			memo[cur + 1] = cur;
			Q.push({ cnt + 1, cur + 1 });
		}
		if (cur * 2 <= 100000 && memo[cur * 2] < 0)
		{
			memo[cur * 2] = cur;
			Q.push({ cnt + 1, cur * 2 });
		}
	}
}

const int MAX = 500000;
bool memo2[2][500001]{};
void solution5()
{
	cin >> s >> d;

	queue<int> Q;
	Q.push(s);
	memo2[0][s] = true;

	int cnt = 0;
	int curD = d;

	while(!Q.empty())
	{
		int qsz = Q.size();
		curD += cnt;
		if (curD > MAX) break;
		if (memo2[cnt & 1][curD]) { cout << cnt; return; }
		cnt++;
		while (qsz--)
		{
			auto cur = Q.front();
			Q.pop();

			for(auto it : {cur - 1, cur + 1, cur * 2})
			{
				if (it < 0 || it > MAX || memo2[cnt & 1][it]) continue;
				memo2[cnt & 1][it] = true;
				Q.push(it);
			}
		}
	}

	cout << -1;
}

int GCD(int a, int b)
{
	if(b == 0)	return a;
	else return GCD(b, a % b);
}

void solution6()
{
	int n, s;
	cin >> n >> s;

	int gcd;
	cin >> gcd;
	gcd = abs(s - gcd);
	for (int i = 1; i < n; ++i)
	{
		int nxt;
		cin >> nxt;
		nxt = abs(s - nxt);
		gcd = GCD(gcd, nxt);
	}

	cout << gcd;
}

int main()
{
	fastio;

	solution5();

	return 0;
}


// S : 315
// U : 
// T : 
// C :
// Total :