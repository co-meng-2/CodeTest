#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <string>

#include <algorithm>

int main()
{
	fastio;

	std::string s1;
	std::string s2;
	cin >> s1 >> s2;

	int s1len = s1.length();
	int s2len = s2.length();

	vector<vector<int>> dp(s1len + 1, vector<int>(s2len + 1, 0));

	for(int i = 1; i <= s1len; i++)
	{
		for(int j = 1; j <= s2len; j++)
		{
			if (s1[i-1] == s2[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	std::string ans;
	int s = dp[s1len][s2len];
	int cy = s1len;
	int cx = s2len;
	while(s > 0)
	{
		while (dp[cy][cx] == s)
			cx--;
		cx++;
		while (dp[cy][cx] == s)
			cy--;
		cy++;
		ans.push_back(s1[cy - 1]);
		cx--;
		cy--;
		s--;
	}

	cout << dp[s1len][s2len] << "\n";
	for(auto it = ans.rbegin(); it != ans.rend(); it++)
	{
		cout << *it;
	}

	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :