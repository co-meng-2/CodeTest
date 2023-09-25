#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <climits>

#include <queue>
using std::queue;

// 수빈이 N 동생 K
// 수빈이 걷거나 순간이동
// 걷기 +-1
// 순간이동 2*현재위치
// 수빈이가 동생을 찾을 수 있는 가장 빠른 시간 + 방법이 몇 가지?

// N - 0 - 100,000
// K - 0 - 100,000

// 풀이
// 칸에 이동 횟수, 현재 이동 횟수로 도착한 횟수 기록
// 다시 그 칸에 도착했을 때, 이동 횟수가 더 적다면 -> 이동 횟수와 도착한 횟수 바꿔줌

int N, K;

const int INF = INT_MAX;
struct tInfo
{
	int curPos;
	int moveCnt = INF;
	int cnt = 0;
};

tInfo arr[100001]{};

void CheckAndPush(tInfo& front, queue<tInfo>& Q, int add)
{
	tInfo* ref = nullptr;
	if (front.curPos + add >= 0 && front.curPos + add <= 100000)
	{
		ref = &arr[front.curPos + add];
		if (ref->moveCnt > front.moveCnt)
		{
			ref->moveCnt = front.moveCnt;
			ref->cnt = 1;
			Q.push({ front.curPos + add, front.moveCnt, });
		}
		else if (ref->moveCnt == front.moveCnt)
		{
			ref->cnt++;
			Q.push({ front.curPos + add, front.moveCnt, });
		}
	}
}

int main()
{
	cin >> N >> K;

	arr[N] = { N, 0, 1 };
	queue<tInfo> Q;
	Q.push(arr[N]);

	while(!Q.empty())
	{
		auto front = Q.front();
		Q.pop();

		front.moveCnt++;

		CheckAndPush(front, Q, -1);
		CheckAndPush(front, Q, 1);
		CheckAndPush(front, Q, front.curPos);
	}

	cout << arr[K].moveCnt << "\n" << arr[K].cnt;

	return 0;
}