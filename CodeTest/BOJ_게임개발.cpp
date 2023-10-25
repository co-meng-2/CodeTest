#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL);
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

// 문제
// 모든 건물을 짓는데 거리는 최소의 시간
// 건물의 선행순서가 있다

// 입력
// n 건물의 종류수
// 시간 건물을 짓기 위해 먼저 지어져야하는 건물들의 번호
// 각 줄은 -1로 끝남
// 여러 개의 건물은 동시에 지을 수 있다.

// 걸리는 시간은 100,000 이하 자연수

// 풀이
// 먼저 지어도 되는 건물 다 지음
// 오래 걸리는 애들을 먼저 지으면 좋다.
// 근데 동시에 지을 수 있으니까 그냥 순서대로 지으면 될 듯?
// 가능한 애들을 짓는다.

struct tInfo
{
	vector<int> next;
	vector<int> neces;
	int time;
	int startTime = -1;

	bool operator>(const tInfo& _rhs) const
	{
		return startTime < _rhs.startTime;
	}
};

vector<tInfo> buildings;

void downSearch(int idx)
{
	if (buildings[idx].startTime == 0) return;

	int Max = -1;
	for(auto neces : buildings[idx].neces )
	{
		if (buildings[neces].startTime == -1)
			downSearch(neces);
		Max = std::max(Max, buildings[neces].startTime + buildings[neces].time);
	}
	buildings[idx].startTime = Max;
}

int main()
{
	int buildingCnt;
	cin >> buildingCnt;
	buildings.resize(buildingCnt+1);

	for(int i = 1; i <= buildingCnt; ++i)
	{
		int time;
		cin >> time;
		buildings[i].time = time;

		while(true)
		{
			int neces;
			cin >> neces;
			if (neces == -1)
			{
				if(buildings[i].neces.empty()) 	buildings[i].startTime = 0;
				break;
			}

			buildings[i].neces.push_back(neces);
			buildings[neces].next.push_back(i);
		}
	}

	for(int i = 1; i <= buildingCnt; ++i)
	{
		if(buildings[i].next.empty())
		{
			downSearch(i);
		}
	}

	for(int i = 1; i <= buildingCnt; ++i)
	{
		cout << buildings[i].time + buildings[i].startTime << "\n";
	}

	return 0;
}

// U : 4:34 - 4:36	2min
// T : 4:43			7min
// C : 5:52			1:09min
// T :				78min