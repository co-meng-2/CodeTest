#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL);
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <queue>
using std::queue;
using std::priority_queue;

// N명의 사원이 대기
// 데카는 K+1번쨰로 줄을 섰다.
// M개의 줄로 나눠서 대기
// 1번째 1번째 줄 2번째 2번째줄.... M+1번째 1번째 줄
// M개의 줄 중 선두에서 근무 일수가 높은 선두가 화장실 이용
// 근무 일수 동일하면 급한 정도가 높은 선두가 화장실 이용
// 다 같다면, 줄 번호가 가장 낮은 줄이 이용


// 대기 사원의 수	N 1 - 10e5
// 줄의 수			M 2 - 10e5
// 자신의 앞에 서있던 사원의 수 K 0 - N-1
// Di, Hi가 순서대로 주어짐

// 문제
// 데카가 화장실 이용하기 전 몇 명의 사원이 화장실을 이용하는지 구하라!

// 풀이
// vector<queue<>>를 만들어 앞 쪽을 다 비교, 가장 우선순위가 높은 애를 빼줌.
// M*N ->  1행으로 서있는 경우 문제가 된다. (100000 * 100001 / 2)
// 따라서 앞 애들만 빼서 먼저 priority_queue를 하나 만든다.
// pop front하고, 빼준 애의 줄에서 다시 가져와 추가해준다.
// 데카의 큐에서의 순서를 기억한다.
// 데카가 priority_queue에서 빠질 때 앞에 빠진 사원의 수를 쓴다.
// NlogN

int N, M, K;

struct tHDM
{
	int D;
	int H;
	int M;

	bool operator<(const tHDM& _rhs) const
	{
		bool bd = D == _rhs.D;
		bool bh = H == _rhs.H;
		if (bd && bh)
			return M > _rhs.M;
		else if (bd)
			return H < _rhs.H;
		else
			return D < _rhs.D;
	}
};



int main()
{
	cin >> N >> M >> K;

	vector<queue<tHDM>> HDM(M+1);

	// 여기서 오류 -> deca는 K+1번째 있지만, 나는 인덱스를 이용해 Col과 Row를 갱신하고 있으므로 (K+1)로 계산하면 안된다.
	int decaCol = K / M + 1;
	int decaRow = K % M + 1;

	// make queueHDM
	for(int i = 0; i < N; ++i)
	{
		int d, h;
		cin >> d >> h;
		int m = i % M + 1;
		HDM[m].push({ d, h, m });
	}

	priority_queue<tHDM> PQ;


	// 초기 PQ
	for(int i = 1; i < HDM.size(); ++i)
	{
		if (HDM[i].empty()) continue;
		PQ.push(HDM[i].front());
		HDM[i].pop();
	}

	int cnt = 0;
	int decaColCnt = 1;
	while(true)
	{
		auto top = PQ.top();
		PQ.pop();
		if (top.M == decaRow)
		{
			if (decaColCnt == decaCol)
				break;
			else
				decaColCnt++;
		}
		cnt++;

		if (HDM[top.M].empty()) continue;
		PQ.push(HDM[top.M].front());
		HDM[top.M].pop();
	}

	cout << cnt;

	return 0;
}

// 48분