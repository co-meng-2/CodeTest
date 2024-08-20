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
#include <unordered_set>
#include <set>
#include <string>
#include <cmath>
#include <memory.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

int main()
{
	fastio;

	int m, n;
	cin >> m >> n;

	vector<int> add(2*m);

	for(int i = 0; i < n; ++i)
	{
		int zero, one, two;
		cin >> zero >> one >> two;

		if (one)
		{
			add[zero] += 1;
			add[zero + one] += -1;
		}

		if (two)
		{
			add[zero + one] += 2;
			add[zero + one + two] += -2;
		}
	}

	for (int i = 1; i < 2 * m; ++i)
		add[i] += add[i - 1];

	for(int i = 0; i < m; ++i)
	{
		for(int j = 0; j < m;++j)
		{
			if (j == 0)
				cout << 1 + add[m - 1 -i] << " ";
			else
				cout << 1 + add[m - 1 + j] << " ";
		}
		cout << "\n";
	}

	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :
