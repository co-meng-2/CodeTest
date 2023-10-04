#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)

using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <queue>
using std::queue;

#include <algorithm>
#include <cstring>


// �Ϻ� ��ǵ��� �� �� ���谡 �־����� ��, ��� ��ǵ��� ���İ��踦 �� �� ������?

// n �˰� �ִ� ����� ���� ������ �� 1- 400
// k ���� ���踦 �˰� �ִ� �� ����� ��ȣ
// ���� ��ȣ�� ���� ��ȣ�� ��Ǻ��� ���� �Ͼ��
// s ����� ���� ���踦 �� �� ���� ��� ���� �� 1-50'000

// ����
// s�ٿ� ���� ������ ���Ѵ�. ���� ��ȣ ����� ���� �Ͼ���� -1, ���� ��ȣ�� 1, �𸣸� 0

// � �ڷᱸ���� ������ �� ��?
// 1 > 2  2 > 3
// �ڱ⺸�� ���� ����� ���ͷ� ��� �ְ�, ��� �� ���� ������� Ž���ϸ� ���� ������?
// �ٵ� �׷��� 1 > 2 2 > 3 1 > 3 1 > 4 2 > 4 3 > 4 �̷� ��쿡 O(n^2) ����
// bfs�� visited check�ϸ� Ž��
// �̷��� �ص� ���� ��ο� ���� �˻��� ��� �ߺ� �� ��.
// �÷��̵带 ��� �Ѵ�.

int N, K, S;

vector<int> cases[401]{};
bool visited[401]{};
bool floyd[401][401]{};

int main()
{
	fastio;

	cin >> N >> K;

	for(int i = 0; i < K; ++i)
	{
		int cur, prev;
		cin >> cur >> prev;
		floyd[cur][prev] = true;
	}

	for (int k = 1; k <= N; ++k)
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				if (floyd[i][j] == false && floyd[i][k] && floyd[k][j])
					floyd[i][j] = true;

	cin >> S;

	for(int i = 0; i < S; ++i)
	{
		int first, second;
		cin >> first >> second;

		if (floyd[first][second]) cout << -1 << "\n";
		else if (floyd[second][first]) cout << 1 << "\n";
		else cout << 0 << "\n";
	}

	// BFS - �ð��ʰ�
	// �� �Ǵ� ���� -> BFS�� �ð����⵵�� O(V+E) E�� Dense�Ұ�� N^2�̰� ���������� 50000���� ���������� �׷��� 50000*S = 25������ �ð��ʰ�
	//for (int i = 1; i <= K; ++i)
	//{
	//	int cur, prev;
	//	cin >> cur >> prev;
	//	cases[cur].push_back(prev);
	//}
	//for(int i = 0; i < S; ++i )
	//{
	//	int first;
	//	int second;

	//	cin >> first >> second;

	//	// first -> to lower
	//	queue<int> Q1;
	//	visited[first] = true;
	//	Q1.push(first);

	//	memset(visited, 0, sizeof(bool) * 401);

	//	bool b1 = false;
	//	while (!Q1.empty())
	//	{
	//		auto front = Q1.front();
	//		Q1.pop();

	//		if(front == second)
	//		{
	//			b1 = true;
	//			break;
	//		}

	//		for(int j = 0; j < cases[front].size(); ++j)
	//		{
	//			if (visited[cases[front][j]]) continue;
	//			visited[cases[front][j]] = true;
	//			Q1.push(cases[front][j]);
	//		}
	//	}

	//	memset(visited, 0, sizeof(bool) * 401);

	//	queue<int> Q2;
	//	visited[second] = true;
	//	Q2.push(second);

	//	bool b2 = false;
	//	while (!Q2.empty())
	//	{
	//		auto front = Q2.front();
	//		Q2.pop();

	//		if (front == first)
	//		{
	//			b2 = true;
	//			break;
	//		}

	//		for (int j = 0; j < cases[front].size(); ++j)
	//		{
	//			if (visited[cases[front][j]]) continue;
	//			visited[cases[front][j]] = true;
	//			Q2.push(cases[front][j]);
	//		}
	//	}

	//	if (b1) cout << -1 << "\n";
	//	else if (b2) cout << 1 << "\n";
	//	else cout << 0 << "\n";
	//}

	return 0;
}

// U : 3min
// T : 6min
// C : 1h15min