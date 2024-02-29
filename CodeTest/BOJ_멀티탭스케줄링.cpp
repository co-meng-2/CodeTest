#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <set>
#include <queue>

#include <algorithm>

int main()
{
	fastio;

	int N, K;
	cin >> N >> K;

	vector<int> schedule(K);
	vector<std::queue<int>> priority(K+1);
	for (int i = 0; i < K; ++i)
	{
		cin >> schedule[i];
		priority[schedule[i]].push(i);
	}

	std::set<int> multitap;
	int sum = 0;
	for (int i = 0; i < schedule.size(); ++i)
	{
		if (multitap.size() < N)
		{
			multitap.insert(schedule[i]);
			priority[schedule[i]].pop();
		}
		else
		{
			if (multitap.find(schedule[i]) != multitap.end())
			{
				priority[schedule[i]].pop();
				continue;
			}

			int max = -1;
			int maxIdx = -1;
			for (auto iter : multitap)
			{
				if (priority[iter].empty())
				{
					max = 10000;
					maxIdx = iter;
					break;
				}
				else if (max < priority[iter].front())
				{
					max = priority[iter].front();
					maxIdx = iter;
				}
			}
			
			if (max == -1)
				multitap.erase(multitap.begin());
			else
				multitap.erase(maxIdx);
			sum++;
			multitap.insert(schedule[i]);
			priority[schedule[i]].pop();
		}
	}

	cout << sum;

	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :