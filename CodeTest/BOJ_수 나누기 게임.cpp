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

// 에라토스테네스 변형?

int n;
bool nums[1000001];
int scores[1000001];
int order[100001];


int main()
{
	fastio;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		nums[num] = true;
		order[i] = num;
	}
		
	for(int i = 1; i <= 1000000; ++i)
	{
		if (nums[i] == false) continue;

		for(int j =  2 * i; j <= 1000000; j += i)
		{
			if(nums[j])
			{
				++scores[i];
				--scores[j];
			}
		}
	}

	for(int i = 0; i< n; ++i)
	{
		cout << scores[order[i]] << " ";
	}

	return 0;
}


// S : 9 44
// U : 9 46
// T : 9 53
// C : 9 58
// Total : 14min
