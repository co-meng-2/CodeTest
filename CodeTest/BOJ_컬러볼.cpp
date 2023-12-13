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

// brute -> 200000 * 200000 -> 400억
// size로 공들을 정렬
// 전체 합과 각 숫자의 합을 계산해놓고 어떤 공의 차례에 전체 합에서 그 전까지의 숫자의 합을 빼서 점수를 계산

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
		// 현재 공 balls[i] 이전 전체합에서 이전 숫자합을 빼주기
		score[balls[i].idx] = sum - numSum[balls[i].color];

		// 틀린 곳 : 1 1 / 2 1 / 3 1과 같이 크기만 같은 경우에 대한 예외처리가 필요함.
		// 이전 공부터 같은 size를 가진 공을 탐색하며 점수를 줄여줌. 
		int cur = i-1;
		while (cur > 0 && balls[cur].size == balls[i].size)
		{
			if (balls[cur].color != balls[i].color)
			{
				score[balls[i].idx] -= balls[cur].size;
			}
			cur--;
		}

		// 현재 공을 전체합과 숫자합에 반영함.
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
// 클리너로 파일 삭제했다가 디버깅 기호 파일 삭제되서 20분 잡아먹은듯