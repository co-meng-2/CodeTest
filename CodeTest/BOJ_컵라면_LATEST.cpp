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
#include <memory.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int INF = 0x3f3f3f3f;

int main()
{
	fastio;

	int n;
	cin >> n;
	vector<vector<int>> nums(n + 1);
	for(int i = 0; i < n; ++i)
	{
		int deadline, ramen;
		cin >> deadline >> ramen;

		nums[deadline].push_back(ramen);
	}

	priority_queue<int> PQ;
	int ans = 0;
	for(int time = n ; time > 0; --time)
	{
		for (auto it : nums[time])
			PQ.push(it);

		if(!PQ.empty())
		{
			ans += PQ.top();
			PQ.pop();
		}
	}

	cout << ans;

	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :