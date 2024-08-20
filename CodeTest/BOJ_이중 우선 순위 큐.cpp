#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include <cmath>
#include <memory.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

int main()
{
	fastio;

	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		priority_queue<pii> PQDec;
		priority_queue<pii, vector<pii>, greater<pii>> PQInc;
		vector<bool> erased(n);

		while(n--)
		{
			char order;
			int num;
			cin >> order;
			cin >> num;

			if(order == 'I')
			{
				PQDec.push({ num, n });
				PQInc.push({ num, n });
			}
			else
			{
				if (num == 1)
				{
					while(!PQDec.empty() && erased[PQDec.top().second])
						PQDec.pop();

					if (PQDec.empty()) continue;

					erased[PQDec.top().second] = true;
					PQDec.pop();
				}
				else if(num == -1)
				{
					while (!PQInc.empty() && erased[PQInc.top().second])
						PQInc.pop();

					if (PQInc.empty()) continue;

					erased[PQInc.top().second] = true;
					PQInc.pop();
				}
			}
		}

		while (!PQDec.empty() && erased[PQDec.top().second])
			PQDec.pop();
		while (!PQInc.empty() && erased[PQInc.top().second])
			PQInc.pop();

		if (!PQDec.empty() && !PQInc.empty())
			cout << PQDec.top().first << " " << PQInc.top().first;
		else
			cout << "EMPTY";
		cout << "\n";
	}

	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :
