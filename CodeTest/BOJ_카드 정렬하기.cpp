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
	priority_queue<int, vector<int>, greater<>> PQ;
	for(int num, i = 0; i < n; ++i)
	{
		cin >> num;
		PQ.push(num);
	}

	int ans = 0;
	while(PQ.size() != 1)
	{
		auto a = PQ.top();
		PQ.pop();
		auto b = PQ.top();
		PQ.pop();
		ans += a + b;
		PQ.push(a + b);
	}

	cout << ans;
	


	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :