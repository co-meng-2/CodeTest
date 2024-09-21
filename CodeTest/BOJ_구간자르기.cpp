#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using namespace std;

// 길이이므로 구간 [x - 1,x]을 인덱스 x로 생각
// 매개변수 탐색으로 nlogn 100만에 대해 가능

int n, k;
int acc[1000005]{};

void solve_parametric_search()
{
	for (int i = 1; i <= 1000001; ++i)
		acc[i] += acc[i - 1];

	for (int i = 1; i <= 1000000; ++i)
		acc[i] += acc[i - 1];

	for (int i = 0; i <= 1000000; ++i)
	{
		int lo = 0;
		int hi = 999999;

		while (lo <= hi)
		{
			int mid = (lo + hi) / 2;
			// [i, mid]
			if (acc[mid] - acc[i] < k)
				lo = mid + 1;
			else
				hi = mid - 1;
		}

		if (acc[lo] - acc[i] == k)
		{
			cout << i << " " << lo;
			return;
		}
	}

	cout << "0 0";
}

void solve_two_pointer()
{
	for (int i = 1; i <= 1000001; ++i)
		acc[i] += acc[i - 1];

	int lo = 0;
	int hi = 0;

	int sum = 0;

	while(hi <= 1000000)
	{
		if (sum < k)
		{
			++hi;
			sum += acc[hi];
		}
		else if(sum > k)
		{
			++lo;
			sum -= acc[lo];
		}
		else
		{
			cout << lo << " " << hi;
			return;
		}
	}

	cout << "0 0";
}

int main()
{
	fastio;

	cin >> n >> k;
	for(int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		++acc[a + 1];
		--acc[b + 1];
	}

	solve_two_pointer();

}


// S : 9 22 
// U : 9 22
// T : 9 28
// C : 10 12
// Total : 50min

// Comment
// 구간에 대한 인덱스를 사용하는게 익숙치 않아서 머리가 아팠다..
