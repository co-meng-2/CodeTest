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

// 1 ~ n까지의 구간합들을 알면 모든 구간합을 계산할 수 있다.
// 어떤 구간합에서 어떤 구간합을 뺐을 때, 값이 0이라면 둘은 m으로 나누어진다.
// 결국 구간 합에 나머지 연산을 추가해 나머지들을 구하고, 그 나머지가 같은 것들을 찾으면 된다. ( 나머지가 같다는 것은 뺐을 때 0이 된다는 것. )
// 예외적으로 두 구간 합의 연산결과가 아닌, 한 구간 합이 0인 경우에는 그 자체도 정답이 될 수 있다.

int n, m;
ll ans = 0;
int main()
{
	fastio;

	cin >> n >> m;

	vector<int> nums(n);
	for (int i = 0; i < n; ++i)
		cin >> nums[i];

	vector<int> infos(m);
	infos[nums[0] % m] = 1;
	for (int i = 1; i < n; ++i)
	{
		// acc
		nums[i] = (nums[i] + nums[i - 1]) % m;
		ans += infos[nums[i]];
		infos[nums[i]]++;
	}
	ans += infos[0];

	cout << ans;

	return 0;
}

// 11 3
// 0 1 0 0 2 3 0 0 1 0 2

// S : 10 04
// U : 10 05
// T : 11 20
// C : 11 42
// Total : 1h 38min

// Comment
// 문제를 잘못 읽어서 시간을 너무 허비함..