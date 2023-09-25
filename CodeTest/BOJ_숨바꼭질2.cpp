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

// ������ N ���� K
// ������ �Ȱų� �����̵�
// �ȱ� +-1
// �����̵� 2*������ġ
// �����̰� ������ ã�� �� �ִ� ���� ���� �ð� + ����� �� ����?

// N - 0 - 100,000
// K - 0 - 100,000

// Ǯ��
// ĭ�� �̵� Ƚ��, ���� �̵� Ƚ���� ������ Ƚ�� ���
// �ٽ� �� ĭ�� �������� ��, �̵� Ƚ���� �� ���ٸ� -> �̵� Ƚ���� ������ Ƚ�� �ٲ���

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