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
using tiii = tuple<int, int, int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

// 작은 음수 끼리 묶고
// 큰 양수 끼리 묶고
// -> 음수 0~1개 양수 0~1개 남는 경우
// 0도 생각

int main()
{
	fastio;

	int n;
	cin >> n;

	deque<int> deq;

	int ans = 0;
	bool hasZero = false;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		if (num == 0)
			hasZero = true;
		else if (num == 1)
			ans += 1;
		else
			deq.push_back(num);
	}

	sort(deq.begin(), deq.end());

	
	while(deq.size() >= 2 && deq[1] < 0)
	{
		ans += deq[0] * deq[1];
		deq.pop_front();
		deq.pop_front();
	}

	// 1인 경우 곱하는 것이 손해
	while (deq.size() >= 2 &&  deq[deq.size()-2] > 1)
	{
		ans += deq[deq.size() - 1] * deq[deq.size() - 2];
		deq.pop_back();
		deq.pop_back();
	}

	if(!deq.empty())
	{
		if (deq.back() > 0)
			ans += deq.back();

		if (!hasZero && deq.front() < 0)
			ans += deq.front();
	}

	cout << ans;

	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :
