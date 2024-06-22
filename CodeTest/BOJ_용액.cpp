#include <iostream>
#include "MyDebug.h"
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

// 100000 C 2 -> 초과
// 앞 쪽은 가장 뒤 쪽과 매칭되어야 함


// 2. 이분탐색
// 합이 <= 0 이면 앞 쪽에 있던 것이 앞으로 가야함.
// -e 보다 큰 값을 찾음 -> 새로운 s에 대한 s, s-1 e간의 합에 절댓값 비교.

// 쓰레기 짓!~~~
void solution_bi(vector<int>& nums, int n)
{
	if (nums[0] >= 0)
	{
		cout << nums[0] << " " << nums[1];
		return;
	}
	else if (nums.back() <= 0)
	{
		cout << nums[n - 2] << " " << nums[n - 1];
		return;
	}


	int ans1, ans2;

	int s = 0;
	int e = n - 1;
	ll mn = 1e13;

	// e 혹은 s와 가장 가까운 애부터 시작 - 추가

	while (s < e)
	{
		int sum = nums[s] + nums[e];
		if (mn > abs(sum))
		{
			ans1 = s;
			ans2 = e;
			mn = abs(sum);
		}

		if (sum > 0)
		{
			if (s - 1 >= 0 && mn > abs(nums[s - 1] + nums[e]))
			{
				ans1 = s - 1;
				ans2 = e;
				mn = abs(nums[s - 1] + nums[e]);
			}
		}
		else
		{
			if (e + 1 < n && mn > abs(nums[s] + nums[e + 1]))
			{
				ans1 = s;
				ans2 = e + 1;
				mn = abs(nums[s] + nums[e + 1]);
			}
		}

		if (sum <= 0)
			s = upper_bound(nums.begin(), nums.end(), -nums[e]) - nums.begin(); // sum -> + 
		else
			e = upper_bound(nums.begin(), nums.end(), -nums[s]) - nums.begin() - 1; // sum -> 0, -
	}

	if (e + 1 < n && mn > abs(nums[e] + nums[e + 1]))
	{
		ans1 = e;
		ans2 = e + 1;
		mn = abs(nums[e] + nums[e + 1]);
	}

	if (e - 1 >= 0 && mn > abs(nums[e - 1] + nums[e]))
	{
		ans1 = e - 1;
		ans2 = e;
		mn = abs(nums[e - 1] + nums[e]);
	}

	cout << nums[ans1] << " " << nums[ans2] << "\n";
}

void solution(vector<int>& nums, int n)
{
	int ans1, ans2;
	ll mn = 1e13;
	int s = 0;
	int e = n - 1;

	while (s < e)
	{
		int sum = nums[s] + nums[e];
		if (abs(sum) < mn)
		{
			mn = abs(sum);
			ans1 = nums[s];
			ans2 = nums[e];
		}

		if (sum < 0)
			s++;
		else
			e--;
	}

	cout << ans1 << " " << ans2 << "\n";
}


int main()
{
	fastio;

	int n;
	cin >> n;
	vector<int> nums(n);
	
	
	DIS(-1e9, 1e9);
	for (int i = 0; i < n; ++i)
		nums[i] = dis(rd);
	sort(nums.begin(), nums.end());

	D_CURTIME;
	solution(nums, n);
	cout << "binary : "; D_ELAPSETIME;

	D_CURTIME;
	//solution_bi(nums, n);
	cout << "sweep : "; D_ELAPSETIME;

	


	return 0;
}




// S : 
// U : 
// T : 
// C :
// Total :