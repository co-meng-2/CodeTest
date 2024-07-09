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

int memo[1000001]{};

int main()
{
	fastio;

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		memo[num] = memo[num - 1] + 1;
	}

	cout << n - *max_element(memo, memo + n + 1);

	return 0;
}


// S : 700
// U : 701
// T : 712
// C : 714
// Total : 14min

// Comment
// LIS가 아닌 연속된 숫자 ( 2 3 4 / 11 12 13 14 ....)중 가장 긴 길이를 구해야 하는 문제였다.
// 이런 경우에는 LIS가 아닌 dp, memo를 이용해서 풀 수 있었다.
