#include <iostream>
#include "MyDebug.h"
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
#include <deque>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;


int board[10][10]{};
int ingre[10][10]{};
deque<int> trees[10][10]{};

int dx[3] = { 1, -1, 0 };
int dy[3] = { 1, -1, 0 };

int main()
{
	fastio;
	deque<int> a(1000000);
	D_CURTIME;
	for (auto i = 0; i < a.size(); ++i)
	{

	}
	
	D_ELAPSETIME;

	D_CURTIME;
	for (auto it : a)
	{

	}
	D_ELAPSETIME;


	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
		{
			cin >> ingre[i][j];
			board[i][j] = 5;
		}

	int x, y, w;
	for (int i = 0; i < M; ++i)
	{
		cin >> x >> y >> w;
		trees[x-1][y-1].push_back(w);
	}

	int year = 0;
	while(year++ < K)
	{
		for(int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				for(auto it = trees[i][j].begin(); it != trees[i][j].end(); ++it)
					if(*it <= board[i][j])
					{
						board[i][j] -= *it;
						(*it)++;
					}
					else
					{
						for (auto it2 = it; it2 != trees[i][j].end(); ++it2)
							board[i][j] += *it2 / 2;
						trees[i][j].erase(it, trees[i][j].end());
						break;
					}

		auto OOB = [&](int y, int x)->bool
		{
			return y < 0 || x < 0 || y >= N || x >= N;
		};

		vector<pii> add;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				for (auto it = trees[i][j].begin(); it != trees[i][j].end(); ++it)
				{
					if(*it % 5 == 0)
					{
						for(int m = 0; m < 3; ++m)
							for (int n = 0; n < 3; ++n)
							{
								if (dy[m] == 0 && dy[n] == 0) continue;
								int ny = i + dy[m];
								int nx = j + dx[n];
								if (!OOB(ny,nx))
								{
									add.push_back({ny,nx});
								}
							}
					}
				}

		for (auto [y, x] : add)
			trees[y][x].push_front(1);
			

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				board[i][j] += ingre[i][j];
	}

	int sum = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			sum += trees[i][j].size();

	cout << sum;
	// 봄 - 자기 나이만큼 양분 먹고 나이 1 증가 / 여러 나무 있다면 나이 어린 나무부터
	// 여름 - 봄에 죽은 나무가 나이/2 양분으로 변한다
	// 가을 - 나이가 5의 배수이면 인접한 8개 칸에 나이가 1인 나무가 생김
	// 겨울 - 양분을 추가

	

	return 0;
}


// S : 922
// U : 
// T : 
// C :
// Total :