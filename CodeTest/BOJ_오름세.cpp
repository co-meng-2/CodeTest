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

	int n;
	while (cin >> n)
	{
		vector<int> ans;
		for (int i = 0; i < n; ++i)
		{
			int input;
			cin >> input;
			int idx = std::lower_bound(ans.begin(), ans.end(), input) - ans.begin();
			if (idx >= ans.size())
				ans.push_back(input);
			else
				ans[idx] = input;
		}

		cout << ans.size() << "\n";
	}


	return 0;
}


// S : 9:27
// U : 9:27
// T : 9:27
// C :
// Total :