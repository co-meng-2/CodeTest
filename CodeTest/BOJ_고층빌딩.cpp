	#include <iostream>
	#define fastio std::ios_base::sync_with_stdio(false);\
	cin.tie(NULL);
	using std::cin;
	using std::cout;

	#include <vector>
	using std::vector;

	#include <cmath>
	using std::abs;

	// 총 N개
	// 낮은 곳에서 높은 곳을 바라봄
	// 보인다 : 현재 빌딩 - 어떤 빌딩 이었을 떄, 그 선이 다른 빌딩과 접하지 않는다.
	// 접하면 안 됨

	// 빌딩의 수 N 1 - 50
	// 높이 10억 보다 작음

	// 문제
	// 가장 많은 고층 빌딩이 보이는 빌딩에서 보이는 빌딩의 수

	int N;

	int buildings[51]{};
	int ans[51]{};

	int main()
	{
		cin >> N;
		for (int i = 1; i <= N; ++i)
			cin >> buildings[i];

		// 빌딩 당
		for(int i = 1; i <=N; ++i)
		{
			// 다른 빌딩으로
			for(int j = i+1; j <=N; ++j)
			{
				// 잇는다
				double slope = (buildings[i] - buildings[j]) / (double)(i - j);

				bool isMeet = false;

				// 선분을 다른 건물들과 판정
				for(int k = i+1; k <= j-1; ++k)
				{
					// 접한다
					double height = buildings[i] + slope * (k - i);
					if(buildings[k] >= height)
					{
						isMeet = true;
						break;
					}
				}

				if(isMeet == false)
				{
					ans[i]++;
					ans[j]++;
				}
			}
		}

		int Max = -1;
		for (int i = 1; i <= N; ++i)
			Max = std::max(Max, ans[i]);

		cout << Max;

		return 0;
	}