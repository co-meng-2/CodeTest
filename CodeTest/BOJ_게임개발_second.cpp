#include <iostream>
#include <queue>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

struct tEdge
{
	int s;
	int d;
};

bool operator<(const vector<tEdge>& lhs, const vector<tEdge>& rhs)
{
	return lhs.size() < rhs.size();
}

int main()
{
	fastio;

	int n;
	cin >> n;


	vector<int> times(n + 1);
	vector<int> timeTable(n + 1);
	vector<vector<int>> adjList(n+1);
	vector<int> topology(n + 1);
	for(int i = 1; i <= n; ++i)
	{
		int w;
		cin >> w;
		times[i] = w;
		timeTable[i] = w;
		while(true)
		{
			int s;
			cin >> s;
			if (s == -1) break;
			adjList[s].push_back(i);
			topology[i]++;
		}
	}

	std::queue<int> Q;
	for(int i = 1; i <= n; ++i)
	{
		if (topology[i] == 0)
			Q.push(i);
	}


	while(!Q.empty())
	{
		auto front = Q.front();
		Q.pop();

		for(auto it : adjList[front])
		{
			timeTable[it] = std::max(timeTable[front] + times[it], timeTable[it]);
			if (--topology[it] == 0)
				Q.push(it);
		}
	}

	for(int i = 1; i <=n; ++i)
	{
		cout << timeTable[i] << "\n";
	}

	return 0;
}


// S : 4:18
// U : 4:19
// T : 4:20
// C : 5:20
// Total : 1h2min
// 간선을 받는 정점의 topology값이 올라가는 것을 잊지 말자.