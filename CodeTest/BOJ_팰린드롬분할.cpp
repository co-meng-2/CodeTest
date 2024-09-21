#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using namespace std;

// #include "MyDebug.h"

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

// 2500 * 2500 / 2

const int INF = 0x3f3f3f3f;

int memo[2500][2500]{};
int dp[2500];

int main()
{
	fastio;
	
	string str;
	cin >> str;
	
	//for (int i = 0; i < 2500; ++i)
	//	str.push_back(MyDebugRandom::GetInstance()->GetRandomNumber('A', 'Z'));
	
	memset(dp, 0x3f, sizeof(dp));
	for (int i = 0; i < str.size(); ++i)
		for (int j = 0; j <= i; ++j)
		{
			int ti = i;
			int tj = j;
			bool check = true;

			while (tj <= ti)
			{
				if (memo[tj][ti] == 1) 
					break;
				if(memo[tj][ti] == -1)
				{
					check = false;
					break;
				}

				if (str[tj] != str[ti])
				{
					check = false;
					break;
				}

				++tj;
				--ti;
			}

			if (check)
			{
				memo[j][i] = 1;
				dp[i] = min(dp[i], dp[j - 1] + 1);
			}
			else
			{
				memo[j][i] = -1;
			}
		}

	cout << dp[str.size() - 1];


	return 0;
}


// S : 2 31
// U : 2 32
// T : 2 50
// C : 3 03
// Total : 32min
