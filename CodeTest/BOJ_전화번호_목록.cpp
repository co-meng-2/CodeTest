#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>
#include <string>

int c2i(char c)
{
	return c - '0';
}

// 911 9112
bool insert(const std::string& nums, vector<vector<int>>& nxt, vector<bool>& chk, int& unused)
{
	int cur = 1;
	bool bIn = true;
	for (auto num : nums)
	{
		if (nxt[cur][c2i(num)] == -1)
		{
			nxt[cur][c2i(num)] = unused++;
			bIn = false;
		}
		cur = nxt[cur][c2i(num)];

		if (chk[cur])
			return false;
	}

	chk[cur] = true;

	if (bIn)
		return false;
	else
		return true;
}

int main()
{
	fastio;

	int T;
	cin >> T;

	
	while (T--)
	{
		int unused = 2;
		int cnt;
		cin >> cnt;
		int Max = 10 * cnt + 1;
		vector<vector<int>> nxt(Max, vector<int>(10, -1));
		vector<bool> chk(Max);
		vector<std::string> nums(cnt);
		for (int i = 0; i < cnt; ++i)
		{
			cin >> nums[i];
		}

		for(int i = 0; i < cnt; ++i)
		{
			if (insert(nums[i], nxt, chk, unused) == false)
			{
				cout << "NO" << "\n";
				break;
			}

			if (i == cnt - 1)
				cout << "YES" << "\n";
		}
	}

	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :