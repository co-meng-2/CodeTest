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

// Raw하게 계산해봤을 때 16! 은 시간복잡도를 넘어선다.
// 예시 그림에서 4를 우선적으로 선택하고, 나머지의 경우의 수를 생각해 봤을 때, 그렇게 많지는 않아 보인다.
// 따라서 4를 이어 붙여서 만든 형태를 우선적으로 선택했을 때, Raw하게 7을 곱하면 되므로, 시간복잡도를 넘어서진 않을 것이다.

int n, m;
int board[4][4];
bool visited[4][4];

pii NxtPos(int y, int x)
{
	int nx = x + 1;
	int ny = y;
	if(nx == m)
	{
		nx = 0;
		ny = y + 1;
	}
	return pii(ny, nx);
}

int Dfs(int cy = 0, int cx = 0, int val = 0 )
{
	pii nyx = NxtPos(cy, cx);

	if(cy >= n || cx >= m)
	{
		return val;
	}
	
	if(visited[cy][cx])
	{
		return Dfs(nyx.first, nyx.second, val);
	}

	int mx = 0;
	
	for(int i = cy; i < n; ++i)
	{
		if(visited[i][cx])
		{
			break;
		}

		int add = 0;
		for(int j = cy; j <= i; ++j)
		{
			visited[j][cx] = true;
			add += board[j][cx] * pow(10, i - j);
		}
		
		mx = max(mx,  Dfs(nyx.first, nyx.second, val + add));
		
		for(int j = cy; j <= i; ++j)
		{
			visited[j][cx] = false;
		}
	}

	for(int i = cx; i < m; ++i)
	{
		if(visited[cy][i])
		{
			break;
		}
		
		int add = 0;
		for(int j = cx; j <= i; ++j)
		{
			visited[cy][j] = true;
			add += board[cy][j] * pow(10, i - j);
		}
		
		mx = max(mx,  Dfs(nyx.first, nyx.second, val + add));
		
		for(int j = cx; j <= i; ++j)
		{
			visited[cy][j] = false;
		}
	}

	return mx;
}

int main()
{
	fastio;

	cin >> n >> m;
	for(int i = 0; i < n;  ++i)
	{
		string str;
		cin >> str;
		for(int j = 0; j < str.size(); ++j)
		{
			board[i][j] = str[j] - '0';
		}
	}

	cout << Dfs();
	


	return 0;
}


// S : 5 46
// U : 5 47
// T : 5 53
// C : 6 34
// Total : 48min

