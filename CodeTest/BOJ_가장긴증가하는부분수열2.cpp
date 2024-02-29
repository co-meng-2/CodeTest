#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

// DP LIS ÀÌºÐÅ½»ö

bool check(int cmp, int num)
{
	return num > cmp;
}

int main()
{
	fastio;

	int n;
	cin >> n;
	vector<int> ans;
	ans.push_back(-1);

	for(int i =0;i < n; ++i)
	{
		int num;
		cin >> num;

		if(ans.back() < num) 
			ans.push_back(num);
		else
		{
			int lo = 0;
			int hi = ans.size() - 1;

			while(lo + 1 < hi)
			{
				int mid = (lo + hi) / 2;
				if (check(ans[mid], num))
					lo = mid;
				else
					hi = mid;
			}
			ans[hi] = num;
		}
	}

	cout << ans.size() - 1;

	return 0;
}


// S : 11:44 
// U : 11:44
// T : 11:45
// C : 11:53
// Total : 9min