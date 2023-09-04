#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <cstring>
#include <list>
#include <climits>

struct tEdge;
using std::deque;
using std::queue;
using std::vector;
using std::pair;
using std::priority_queue;
using std::map;
using std::string;
using std::greater;
using std::set;
using std::stack;
using std::list;

using std::cout;
using std::cin;
using std::make_pair;
using std::abs;
using std::fill;
using std::max;
using std::min;
using std::swap;
using std::sort;
using std::memcpy;
using std::stof;
using std::find;

int n;
int arr[1'000'001]{};

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];
	arr[0] = -1;

	//// greedy 
	//vector<int> vec;
	//for (int i = 1; i <= n; ++i)
	//{
	//	if (arr[i] != arr[i - 1])
	//		vec.push_back(arr[i]);
	//}
	//long long ans = 0;
	//if(vec.size() == 2)
	//	ans = abs(vec[0] - vec[1]);
	//else
	//{
	//	while (true)
	//	{
	//		int mn = INT_MAX;
	//		int mnIdx = -1;
	//		for (int i = 0; i < vec.size(); ++i)
	//		{
	//			if (mn > vec[i])
	//			{
	//				mn = vec[i];
	//				mnIdx = i;
	//			}
	//		}

	//		// min으로부터 왼쪽 오른쪽 차이
	//		int rightMin = INT_MAX; 
	//		int leftMin = INT_MAX;

	//		if (mnIdx + 1 < vec.size())
	//			rightMin = vec[mnIdx + 1] - vec[mnIdx];

	//		if (mnIdx - 1 >= 0)
	//			leftMin = vec[mnIdx - 1] - vec[mnIdx];

	//		if (leftMin > rightMin)
	//		{
	//			ans += rightMin;
	//			vec.erase(vec.begin() + mnIdx);
	//		}
	//		else if (leftMin < rightMin)
	//		{
	//			ans += leftMin;
	//			vec.erase(vec.begin() + mnIdx);
	//		}
	//		else 
	//		{
	//			if (vec.size() == 1)
	//				break;
	//			else
	//			{
	//				ans += leftMin;
	//				vec.erase(vec.begin() + mnIdx, vec.begin() + mnIdx + 2);
	//			}
	//		}
	//	}
	//}
	// cout << ans << "\n";

	// stack
	long long ans_stk = 0;
	stack<int> stk;

	for (int i = 1; i <= n; ++i)
	{
		if (stk.empty())
			stk.push(arr[i]);
		else
		{
			if (stk.top() < arr[i])
			{
				ans_stk += arr[i] - stk.top();
				while (!stk.empty() && stk.top() < arr[i])
				{
					stk.pop();
				}
				stk.push(arr[i]);
			}
			else if (stk.top() > arr[i])
				stk.push(arr[i]);
		}
	}

	if (!stk.empty())
	{
		int mn = stk.top();
		int mx;
		while (!stk.empty())
		{
			mx = stk.top();
			stk.pop();
		}
		ans_stk += mx - mn;
	}

	cout << ans_stk;

    return 0;
}
	