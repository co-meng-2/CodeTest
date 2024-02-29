#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

int Find(int n, vector<int>& p)
{
	if (p[n] < 0) return n;
	p[n] = Find(p[n], p);
	return p[n];
}

bool Union(int parent, int child, vector<int>& p)
{
	parent = Find(parent, p);
	child = Find(child, p);

	if (parent == child) return false;
	
	p[parent] += p[child];
	p[child] = parent;
	return true;
}

int main()
{
	fastio;

	int n, m;
	cin >> n >> m;

	vector<int> p(n + 1, -1);

	int x, y, z;
	for (int i = 0; i < m; ++i)
	{
		cin >> x >> y >> z;
		
		if (x == 0)
		{
			Union(y, z, p);
		}
		else
		{
			if (Find(y, p) == Find(z, p))
				cout << "YES" << "\n";
			else
				cout << "NO" << "\n";
		}
	}

	return 0;
}


// S : 1:39
// U : 1:40 1min
// T : 1:42 2min 
// C : 1:51 9min
// Total : 12min