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
	// ȸ��
	// �ð� ����
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
		// �ݽð� ����
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

// ������ ũ�Ⱑ �۾����� ������ �ٴڿ� �����ֵ�.
// �������� i -> i��° ����
// ������ ���ǿ��� M���� ������ �����ִ�.
// i��° ���ǿ� ���� j��° ������ ��ġ -> (i,j)�� ǥ��
// �� ���ڵ��� �����¿�� ������
// ���� ȸ���� ������
// ��ȣ�� xi�� ����� ������ di�������� ki��ŭ ȸ�� di 0 �ð� 1�̸� �ݽð�
// ȸ�� �� �����ϸ鼭 ���� ���� ���� ��� ã�� ���� 
// ��� ȸ���� ���� �� ���ǿ� ���� ������ ����?

// N ������ ���� 2-50
// M ���ǿ� ���� ������ ���� 2-50
// ���� ���� ���� 1-1000
// T ������ Ƚ�� 1-50

// ����
// 2�� ���� row ���� �ε��� column ���� ���� ����
// �����¿� �Ǻ��ؼ� ������ �����.
// BFS�� ����ؼ� ����°� ���� ��?

// S : 10:32
// U : 10:38
// T : 10:44