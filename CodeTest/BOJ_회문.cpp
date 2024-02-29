#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>
#include <string>
using std::string;

#include <queue>

// 문자열의 처음 끝을 가리키는 포인터 두개 생성
// 같다면 둘 다 증가
// 다르다면 하나 증가 시켜봄, 그래도 다른 경우 변경한 하나를 다시 복구하고 다른 하나를 변경
// 변경을 이미 했을 때, 다른 경우가 또 나오면 2
// 변경 했을 때 s > e면 1
// 안했으면 0

// 위의 방법은 greedy한 접근으로 baaba의 반례가 있다.
// 따라서 어떤 경우든 앞을 바꾸는 경우와 뒤를 바꾸는 경우 둘 다 탐색해야한다.

struct tInfo
{
	int s;
	int e;
	int changed;
};

int main()
{
	fastio;

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;

		int ans = 2;
		std::queue<tInfo> q;
		q.push({ 0, (int)str.size() - 1, 0 });
		
		while (!q.empty())
		{
			auto [s, e, changed] = q.front();
			q.pop();

			while (s <= e)
			{
				if (str[s] == str[e])
				{
					s++;
					e--;
				}
				else
				{
					changed++;
					if (changed >= 2)
					{
						break;
					}
					else
					{
						q.push({ s + 1, e, changed});
						q.push({ s, e - 1, changed});
						break;
					}
				}
			}
			
			if (s > e)
				ans = std::min(ans, changed);
		}
		cout << ans << "\n";

		// 반례 baaba -> greedy하게 풀 수 없다.
		/*while (true)
		{
			if (s >= e)
			{
				if (bChange)
					cout << 1 << "\n";
				else
					cout << 0 << "\n";
				break;
			}

			if (str[s] == str[e])
			{
				s++;
				e--;
			}
			else
			{
				if (bChange)
				{
					cout << 2 << "\n";
					break;
				}

				bChange = true;
				s++;
				if (str[s] == str[e])
				{
					s++;
					e--;
				}
				else
				{
					s--;
					e--;
					if (str[s] == str[e])
					{
						s++;
						e--;
					}
					else
					{
						cout << 2 << "\n";
						break;
					}
				}
			}
		}*/
	}

	return 0;
}


// S : 10:50
// U : 10:51
// T : 10:58
// C :
// Total :