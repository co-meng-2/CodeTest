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
#include <unordered_set>
#include <set>
#include <string>
#include <cmath>
#include <memory.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

char board[50][50];

// 각 행에서 빈 열이 같다 -> 빈 칸의 갯수의 조작으로 만들 수 있는 최대치를 알 수 있다.

int main()
{
	fastio;

	int n, m;
	cin >> n >> m;

	map<string, pii> check;
	
	for (int i = 0; i < n; ++i)
	{
		string str;
		int cnt = 0;
		for (int j = 0; j < m; ++j)
		{
			char c;
			cin >> c;
			str += c;
			if (c == '0')
				cnt++;
		}
		check[str].first = cnt;
		check[str].second++;
	}

	int k;
	cin >> k;

	vector<int> tmp(51);

	int mx = 0;
	for(auto elem : check)
	{
		int changeCnt = elem.second.first;
		int cnt = elem.second.second;
		if (changeCnt <= k && (changeCnt % 2) == (k % 2))
			mx = max(mx, cnt);
	}


	cout << mx;

	

	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :
