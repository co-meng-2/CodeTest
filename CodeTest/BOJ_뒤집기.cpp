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

// 어떤 칸에 관여 할 수 있는 것은 그 칸의 행, 열을 뒤집는 2가지.
// brute -> 2^20 * 2^20 = 100만 * 100만이라 안 됨.
// 행이나 열 중 하나를 선택해서 모두 뒤집는 경우의 수를 구하고, 거기서 H가 T보다 많다면 뒤집어준다.
// 100만 * 400 이라 6초 안에 통과 가능할 듯.


int n;
bool board[20][20];

int main()
{
	fastio;

	int mn = INF;

	cin >> n;
	for(int i = 0; i< n; ++i)
		for(int j = 0;j<n;++j)
		{
			char c;
			cin >> c;
			if (c == 'T') 
				board[i][j] = true;
		}

	for(int i = 0; i < (1 << n) - 1; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			if(i & (1<<j))
			{
				// j번째 행을 뒤집는다.
				for (int c = 0; c < n; ++c)
					board[j][c] = !board[j][c];
			}
		}

		int sum = 0;
		for (int c = 0; c < n; ++c)
		{
			int cnt = 0;
			for (int r = 0; r < n; ++r)
			{
				if (!board[r][c]) cnt++;
			}

			if (cnt > n / 2)
				sum += n - cnt;
			else
				sum += cnt;
		}

		for (int j = 0; j < n; ++j)
		{
			if (i & (1 << j))
			{
				// 복구
				for (int c = 0; c < n; ++c)
					board[j][c] = !board[j][c];
			}
		}

		mn = min(sum, mn);
	}

	cout << mn;


	return 0;
}


// S : 9 31
// U : 9 31
// T : 9 45
// C : 10 00
// Total : 29min

// Comment
// 골드 1치고는 쉬웠다.