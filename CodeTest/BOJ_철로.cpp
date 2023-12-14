#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

#include <queue>
// 

struct tLine
{
	int s;
	int e;

	bool operator<(const tLine& _rhs) const
	{
		if (e == _rhs.e)
			s < _rhs.s;
		return e < _rhs.e;
	}
};


int main()
{
	fastio;

	int N;
	cin >> N;
	vector<tLine> lines(N);
	for (int i = 0; i < N; ++i)
	{
		int s, e;
		cin >> s >> e;
		if (s > e)
		{
			int tmp = e;
			e = s;
			s = tmp;
		}
		lines[i].s = s;
		lines[i].e = e;
	}
	int d;
	cin >> d;

	std::sort(lines.begin(), lines.end());

	std::priority_queue<int, vector<int>, std::greater<int>> PQ;
	int maxPeople = 0;
	for (auto line : lines)
	{
		if (line.e - line.s <= d)
			PQ.push(line.s);
		else
			continue;

		while (!PQ.empty() && line.e - d > PQ.top())
			PQ.pop();

		maxPeople = std::max(maxPeople, static_cast<int>(PQ.size()));
	}

	cout << maxPeople;


	return 0;
}


// S : 12:26
// U : 12:27
// T : 12:40
// C :
// Total :