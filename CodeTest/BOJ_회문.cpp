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

// ���ڿ��� ó�� ���� ����Ű�� ������ �ΰ� ����
// ���ٸ� �� �� ����
// �ٸ��ٸ� �ϳ� ���� ���Ѻ�, �׷��� �ٸ� ��� ������ �ϳ��� �ٽ� �����ϰ� �ٸ� �ϳ��� ����
// ������ �̹� ���� ��, �ٸ� ��찡 �� ������ 2
// ���� ���� �� s > e�� 1
// �������� 0

// ���� ����� greedy�� �������� baaba�� �ݷʰ� �ִ�.
// ���� � ���� ���� �ٲٴ� ���� �ڸ� �ٲٴ� ��� �� �� Ž���ؾ��Ѵ�.

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

		// �ݷ� baaba -> greedy�ϰ� Ǯ �� ����.
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