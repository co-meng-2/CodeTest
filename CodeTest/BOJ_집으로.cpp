#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL);
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <cmath>
#include <algorithm>

// 문제
// X,Y에서 0,0으로 가려 함
// 걸어서 감 -> 1초에 1만큼
// 점프 -> T초에 D만큼 일직선으로, 정확하게 D만큼만
// 시간의 최솟값은?

// 대각선으로 가는게 무조건 유리
// 넘어가서 돌아오는게 더 빠를 수 도 있음
// 일단 최대한 뛰기로 거리를 좁힘
// 넘어가는 경우와 안 넘어가는 경우 계산

int main()
{
	cout.precision(20);
	int X, Y, D, T;

	cin >> X >> Y >> D >> T;
	vector<double> vecAns;

	double dist = std::sqrt(X * X + Y * Y);
	if (D <= T)
	{
		cout << dist;
		return 0;
	}

	double ansN = 0;

	// 음수 될때까지 빼줌
	int cnt = 0;
	while(dist > 0)
	{
		dist -= D;
		ansN += T;
		cnt++;
	}

	// 점프만 사용해서 구부러진 모양으로 도착
	if (cnt >= 2)
		vecAns.push_back(ansN);
	else
		vecAns.push_back(ansN + T);

	// 점프하고 뒤돌아 걸어오기
	vecAns.push_back(ansN - dist);

	// 점프하고 걸어오기
	double ansP = ansN - T;
	double distP = dist + D;
	vecAns.push_back(ansP + distP);

	std::sort(vecAns.begin(), vecAns.end());
	cout << vecAns[0];

	return 0;
}

// U : 3:46 - 3:47  1min
// T : 3:46 - 3:58  12min (대각선을 생각 못함)
// C : 4:32			34min
// T : 45min