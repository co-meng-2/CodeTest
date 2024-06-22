#include <iostream>
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
using namespace std;

using ll = long long;
using pii = pair<int, int>;

// 100 * 13C6
// 13 12 11 10 9 8 / 6 5 4 3 2 1

int main()
{
	fastio;

	int n, m;
	int board[50][50]{};

	cin >> n >> m;

	vector<pii> houses;
	vector<pii> chickens;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
				houses.push_back({ i,j });
			else if(board[i][j] == 2)
				chickens.push_back({ i,j });
		}

	vector<vector<int>> infos(houses.size());
	for(int i = 0; i < houses.size(); ++i)
		for(int j = 0; j < chickens.size(); ++j)
			infos[i].push_back(abs(houses[i].first - chickens[j].first) + abs(houses[i].second - chickens[j].second));


	vector<bool> sel(chickens.size());
	for (int i = 0; i < m; ++i)
		sel[chickens.size() - 1 - i] = true;

	int ans = 1e9;
	do
	{
		vector<int> mns(houses.size(), 1e9);
		for (int i = 0; i < chickens.size(); ++i)
		{
			if (sel[i])
			{
				for (int j = 0; j < mns.size(); ++j)
					mns[j] = min(mns[j], infos[j][i]);
			}
		}
		int sum = 0;
		for (auto mn : mns)
			sum += mn;
		ans = min(sum, ans);
	} while (next_permutation(sel.begin(), sel.end()));

	cout << ans;

	return 0;
}


// S : 734
// U : 
// T : 
// C :
// Total :