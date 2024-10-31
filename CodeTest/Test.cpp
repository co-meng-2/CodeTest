#include <bits/stdc++.h>

using namespace std;

bool cmp(int i)
{
	return i < 7;
}

int main()
{
	vector<int> a;
	a.push_back(1);
	a.erase(remove_if(a.begin(), a.end(), cmp));

	return 0;
}