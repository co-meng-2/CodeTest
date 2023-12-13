#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

struct tBall
{
	int idx = -1;
	int color;
	int size;

	bool operator<(const tBall& _rhs) const
	{
		return size < _rhs.size;
	}
};

// brute -> 200000 * 200000 -> 400��
// size�� ������ ����
// ��ü �հ� �� ������ ���� ����س��� � ���� ���ʿ� ��ü �տ��� �� �������� ������ ���� ���� ������ ���

int main()
{
	fastio;
	
	int N;
	cin >> N;

	int color, size;
	vector<tBall> balls(N+1);
	for (int i = 1; i <= N; ++i)
	{
		cin >> balls[i].color >> balls[i].size;
		balls[i].idx = i;
	}

	std::sort(balls.begin(), balls.end());
	vector<int> numSum(N + 1);
	vector<int> score(N + 1);
	int sum = 0;
	
	for (int i = 1; i <= N; ++i)
	{
		// ���� �� balls[i] ���� ��ü�տ��� ���� �������� ���ֱ�
		score[balls[i].idx] = sum - numSum[balls[i].color];

		// Ʋ�� �� : 1 1 / 2 1 / 3 1�� ���� ũ�⸸ ���� ��쿡 ���� ����ó���� �ʿ���.
		// ���� ������ ���� size�� ���� ���� Ž���ϸ� ������ �ٿ���. 
		int cur = i-1;
		while (cur > 0 && balls[cur].size == balls[i].size)
		{
			if (balls[cur].color != balls[i].color)
			{
				score[balls[i].idx] -= balls[cur].size;
			}
			cur--;
		}

		// ���� ���� ��ü�հ� �����տ� �ݿ���.
		numSum[balls[i].color] += balls[i].size;
		sum += balls[i].size;
	}

	for (int i = 1; i <= N; ++i)
	{
		cout << score[i] << "\n";
	}

	return 0;
}


// S : 2:57
// U : 3:00
// T : 3:10
// C : 3:57
// Total : 1h
// Ŭ���ʷ� ���� �����ߴٰ� ����� ��ȣ ���� �����Ǽ� 20�� ��Ƹ�����