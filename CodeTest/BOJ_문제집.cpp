#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

#include <queue>

// 먼저 푸는 것이 좋은 문제가 있음
// 가능하면 쉬운 문제부터

// N 문제의 수 1 - 32000
// M 먼저 풀기 정보 수 1- 100000

// 3 -1 , 2 - 1의 경우 2를 먼저 풀어야 함
// 여러 그래프 중 최상단을 보고 가장 낮은 값을 가진 그래프를 선택
// 그 그래프의 가장 최하단(level이 높을수록 우선순위가 높음)을 보고 더 낮은 값을 선택

// 최상단은 부모가 없으면 판정가능
// 최하단은 자식이 없으면 판정 가능.
// 최하단들을 Q에 넣어놓고 가장 작은 것 부터 pop하며 부모가 해금 조건을 갖췄을 때 Q에 push 

struct tInfo
{
	int cur = -1;
	vector<int> parents;
	vector<int> childs;
	bool checked = false;
};

int main()
{
	fastio;

	int N, M;
	cin >> N >> M;

	// 1부터 시작하는 문제들의 인덱스
	// 먼저 풀어야하는 문제(child) 해당 문제를 푼 다음 풀 수 있는 문제(parent)를 가지는 구조체 tInfo 
	vector<tInfo> infos(N + 1);

	// 입력을 자료화 시킨다.
	for (int i = 0; i < M; ++i)
	{
		int next, prev;
		cin >> prev >> next;

		infos[prev].cur = prev;
		infos[prev].parents.push_back(next);
		infos[next].cur = next;
		infos[next].childs.push_back(prev);
	}

	// PQ를 이용해 현재 입력들 중 가장 문제 인덱스가 작은 문제가 top이 되게끔 한다.
	// 자식이 없는 leaf들 즉, 가장 먼저 해결해야하는 문제들을 우선적으로 PQ에 넣는다.
	std::priority_queue<int, vector<int>, std::greater<>> PQ;
	for (int i = 1; i <= N; ++i)
	{
		if (infos[i].childs.empty())
			PQ.push(i);
	}

	// 출력할 벡터
	vector<int> ansOrder;

	// 
	while (!PQ.empty())
	{
		auto top = PQ.top();
		PQ.pop();
		// checked로 문제가 풀렸는지 확인
		infos[top].checked = true;
		// 출력 벡터에 현재 값을 넣어줌
		ansOrder.push_back(top);

		// 해결한 문제의 부모, 다음 문제를 다시 PQ에 넣어주기 전에 그 문제를 풀 수 있는지 확인.
		for (auto parentIdx : infos[top].parents)
		{
			bool allChecked = true;
			// 모든 선행 문제들이 풀렸는가(checked)?
			for (auto childIdx : infos[parentIdx].childs)
				if (infos[childIdx].checked == false)
				{
					allChecked = false;
					break;
				}

			// 다 풀려있다면 다음 문제를 넣어줌
			if (allChecked)
				PQ.push(parentIdx);
		}
	}

	// 정답 출력
	for (auto order : ansOrder)
		cout << order << " ";

	return 0;
}


// S : 1050
// U : 1051
// T : 1116
// C : 1141
// Total : 51