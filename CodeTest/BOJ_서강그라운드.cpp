#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

// floyd

struct tEdge
{
	int d;
	int w;
};

int main()
{
	fastio;

	int v, range, e;
	cin >> v >> range >> e;

	vector<int> vecW(v + 1);
	for (int i = 1; i <= v; ++i)
		cin >> vecW[i];

	const int INF = 100000000;
	vector<vector<int>> floyd(v+ 1, vector<int>(v+1, INF));
	for(int i = 0; i <e ; ++i)
	{
		int s, d, w;
		cin >> s >> d >> w;
		floyd[s][d] = w;
		floyd[d][s] = w;
	}

	for(int k = 1; k <= v; ++k)
	{
		for(int i = 1; i <=v; ++i)
		{
			for(int j =1; j <=v; ++j)
			{
				if (i == j) continue;
				floyd[i][j] = std::min(floyd[i][j], floyd[i][k] + floyd[j][k]);
			}
		}
	}

	int max = 0;
	for(int i = 1; i <=v; ++i )
	{
		int tmpmax = vecW[i];
		for(int j = 1; j <= v; ++j)
		{
			if (floyd[i][j] <= range)
				tmpmax += vecW[j];
		}
		max = std::max(max, tmpmax);
	}

	cout << max;

	return 0;
}


// S : 9:19
// U : 9;21
// T : 9:25 문제를 잘 읽자. -> 떨어지는 곳이 주어지는 줄 알았음.
// C : 9:38
// Total : 19min