#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

// LIS찾기

int nums[100000];

int main()
{
	fastio;

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}

	vector<int> LIS;
	LIS.push_back(nums[0]);


	for(int i = 1; i < n; ++i)
	{
		int num = nums[i];
		int lo = 0;
		int hi = LIS.size() - 1;

		while(lo <= hi)
		{
			int mid = (hi + lo) / 2;
			if (num >= LIS[mid])
				lo = mid + 1;
			else
				hi = mid - 1;
		}

		if (lo == LIS.size())
			LIS.push_back(num);
		else
			LIS[lo] = num;
	}

	cout << n - LIS.size();
	

	return 0;
}


// S : 3 33
// U : 3 35
// T : 3 40
// C :
// Total :