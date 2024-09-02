#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int dx[10] = { 0, -1, 0, 1, -1, 0, 1, -1,  0, 1  };
int dy[10] = { 0, 1 , 1, 1, 0 , 0, 0, -1, -1, -1};

const int INF = 0x3f3f3f3f;

int r, c;
char board[100][100]{};
char board2[100][100]{};

int main()
{
	fastio;

	cin >> r >> c;

	pii adu;
	for(int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 'I')
				adu = { i,j };
		}

	string str;
	cin >> str;
	int step = 0;

	for (auto ch : str)
	{
		memset(board2, '.', sizeof(board2));
		step++;
		auto& [aduy, adux] = adu;
		aduy += dy[ch - '0'];
		adux += dx[ch - '0'];
		if (board[aduy][adux] == 'R')
		{
			cout << "kraj " << step;
			return 0;
		}
		board2[aduy][adux] = 'I';

		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
			{
				if (board[i][j] != 'R') continue;
				auto [cry, crx] = pii{ i,j };
				cry += (aduy - cry == 0) ? 0 : (aduy - cry) / abs(aduy - cry);
				crx += (adux - crx == 0) ? 0 : (adux - crx) / abs(adux - crx);

				if (cry == aduy && crx == adux)
				{
					cout << "kraj " << step;
					return 0;
				}

				if (board2[cry][crx] == 'R' || board2[cry][crx] == 'X')
					board2[cry][crx] = 'X';
				else
					board2[cry][crx] = 'R';
			}

		swap(board, board2);
	}

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (board[i][j] == 'X')
				cout << '.';
			else
				cout << board[i][j];
		}
		cout << "\n";
	}


	return 0;
}


// S : 
// U : 
// T : 
// C : 
// Total : 
