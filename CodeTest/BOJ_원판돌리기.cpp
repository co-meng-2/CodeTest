#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>
#include <queue>
using P = std::pair<int, int>;

struct tRotate
{
	int x;
	int d;
	int k;
};

void Rotate(tRotate rot, vector<vector<int>>& circles, vector<vector<bool>>& visited)
{
	// 회전
	// 시계 방향
	int N = circles.size()-1;
	int M = circles[1].size();

	for (int x = 1; x <= N; ++x)
	{
		if (x % rot.x != 0) continue;

		vector<int> replace(M);
		vector<bool> vreplace(M);
		if (rot.d == 0)
		{
			for(int i = 0; i < M; ++i)
			{
				replace[i] = circles[x][(i - rot.k + M) % M];
				vreplace[i] = visited[x][(i - rot.k + M) % M];
			}
		}
		// 반시계 방향
		else
		{
			for (int i = 0; i < M; ++i)
			{
				replace[i] = circles[x][(i + rot.k) % M];
				vreplace[i] = visited[x][(i + rot.k) % M];
			}
		}
		circles[x] = replace;
		visited[x] = vreplace;
	}

	bool totalFind = false;
	for(int i = 1; i <= N; ++i)
	{
		for(int j = 0; j < M; ++j)
		{
			if (visited[i][j]) continue;
			// bfs
			std::queue<P> Q;
			Q.push({i,j});

			bool bfind = false;
			while(!Q.empty())
			{
				auto front = Q.front();
				Q.pop();

				if (bfind)
				{
					if (visited[front.first][front.second]) continue;
					visited[front.first][front.second] = true;
				}

				// up
				auto next = front;
				if (front.first != 1)
				{
					next.first--;

					if (!visited[next.first][next.second] && circles[next.first][next.second] == circles[front.first][front.second])
					{
						bfind = true;
						visited[front.first][front.second] = true;
						Q.push(next);
					}
				}

				// down
				next = front;
				if (front.first != N)
				{
					next.first++;

					if (!visited[next.first][next.second] && circles[next.first][next.second] == circles[front.first][front.second])
					{
						bfind = true;
						visited[front.first][front.second] = true;
						Q.push(next);
					}
				}

				// left
				next = front;
				if (front.second == 0)
					next.second = M-1;
				else
					next.second--;

				if (!visited[next.first][next.second] && circles[next.first][next.second] == circles[front.first][front.second])
				{
					bfind = true;
					visited[front.first][front.second] = true;
					Q.push(next);
				}


				// right
				next = front;
				if (front.second == M-1)
					next.second = 0;
				else
					next.second++;

				if (!visited[next.first][next.second] && circles[next.first][next.second] == circles[front.first][front.second])
				{
					bfind = true;
					visited[front.first][front.second] = true;
					Q.push(next);
				}
			}
			if (bfind) totalFind = true;
		}
	}

	if (totalFind == false)
	{
		int sum = 0;
		int cnt = 0; 
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (visited[i][j] == false)
				{
					sum += circles[i][j];
					cnt++;
				}
			}
		}

		double avg = static_cast<double>(sum) / cnt;
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (visited[i][j] == false)
				{
					if (circles[i][j] > avg)
						circles[i][j]--;
					else if (circles[i][j] < avg)
						circles[i][j]++;
				}
			}
		}
	}
}



int main()
{
	int N, M, T;
	cin >> N >> M >> T;

	vector<vector<int>> circles(N+1, vector<int>(M));
	for(int i = 1 ; i <= N ;++i)
		for (int j = 0; j < M; ++j)
			cin >> circles[i][j];


	vector<tRotate> rotates;
	for(int i = 0; i< T; ++i)
	{
		int x, d, k;
		cin >> x >> d >> k;
		rotates.push_back({x,d,k});
	}

	vector<vector<bool>> visited(N+1, vector<bool>(M));
	for(int i = 0; i < T; ++i)
	{
		Rotate(rotates[i], circles, visited);
	}

	int sum = 0;
	for(int i = 1; i <= N; ++i)
	{
		for(int j = 0; j < M; ++j)
		{
			if (visited[i][j] == false)
				sum += circles[i][j];
		}
	}

	cout << sum;

	return 0;
}

// 원판의 크기가 작아지는 순으로 바닥에 놓여있따.
// 반지름이 i -> i번째 원판
// 각각의 원판에는 M개의 정수가 적혀있다.
// i번째 원판에 적힌 j번째 숫자의 위치 -> (i,j)로 표현
// 각 숫자들은 상하좌우와 인접함
// 원판 회전은 독립적
// 번호가 xi의 배수인 원판을 di방향으로 ki만큼 회전 di 0 시계 1이면 반시계
// 회전 후 인접하면서 수가 같은 것을 모두 찾아 지움 
// 모든 회전이 끝난 후 원판에 적힌 숫자의 합은?

// N 원판의 갯수 2-50
// M 원판에 적힌 숫자의 갯수 2-50
// 적힌 숫자 범위 1-1000
// T 돌리는 횟수 1-50

// 구현
// 2중 벡터 row 원판 인덱스 column 원판 내의 숫자
// 상하좌우 판별해서 같으면 지운다.
// BFS를 사용해서 지우는게 좋을 듯?

// S : 10:32
// U : 10:38
// T : 10:44