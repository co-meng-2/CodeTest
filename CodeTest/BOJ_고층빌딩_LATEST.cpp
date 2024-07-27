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

	int n;
	cin >> n;
	vector<int> buildings(n);
	for (int i = 0; i < n; ++i)
		cin >> buildings[i];

	vector<int> ans(n);
	for(int i = 0; i < n; ++i)
	{
		for(int j = i + 1; j < n; ++j)
		{
			int diff = buildings[j] - buildings[i];
			double slope = diff / double(j - i);

			bool check = true;
			for (int k = i + 1; k < j; ++k)
			{
				if (slope <= (buildings[k] - buildings[i]) / double(k - i))
				{
					check = false;
					break;
				}
			}
			if (check)
			{
				ans[i]++;
				ans[j]++;
			}
		}
	}

	cout << *max_element(ans.begin(), ans.end());

	return 0;
}


// S : 10 57
// U : 10 58
// T : 10 59
// C : 11 37
// Total : 40min

// Comment
// float를 쓰지 말자. float는 연산에서 오차가 생기는듯.
