#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <cstring>
#include <list>
#include <climits>

struct tEdge;
using std::deque;
using std::queue;
using std::vector;
using std::pair;
using std::priority_queue;
using std::map;
using std::string;
using std::greater;
using std::set;
using std::stack;
using std::list;

using std::cout;
using std::cin;
using std::make_pair;
using std::abs;
using std::fill;
using std::max;
using std::min;
using std::swap;
using std::sort;
using std::memcpy;
using std::stof;
using std::find;

using ll = long long;

enum TYPE
{
	CONSO = 1,
	VOWEL = 2,
	BOTH = 3,
	FILL = 4,
};

int Check(int i, vector<int>& vec)
{
	int result = BOTH;
	if(i -1 >= 0 && i +1 < vec.size())
	{
		if (vec[i - 1] == CONSO && vec[i + 1] == CONSO) result = result & ~CONSO;
		else if (vec[i - 1] == VOWEL && vec[i + 1] == VOWEL) result = result & ~VOWEL;
	}

	if(i -2 >= 0)
	{
		if (vec[i - 2] == CONSO && vec[i - 1] == CONSO) result = result & ~CONSO;
		else if (vec[i - 2] == VOWEL && vec[i - 1] == VOWEL) result = result & ~VOWEL;
	}

	if(i + 2 < vec.size())
	{
		if (vec[i + 2] == CONSO && vec[i + 1] == CONSO) result = result & ~CONSO;
		else if (vec[i + 2] == VOWEL && vec[i + 1] == VOWEL) result = result & ~VOWEL;
	}

	return result;
}

void dfs(int _iDepth, int _iMaxDepth, bool _hasL, vector<int>& _vec, ll _acc, ll& _total)
{
	if (_iMaxDepth == _iDepth)
	{
		if (_hasL == false) return;
		_total += _acc;
		return;
	}

	int i = 0;
	while (_vec[i] != FILL) ++i;

	int check = Check(i, _vec);

	if (check == VOWEL)
	{
		_vec[i] = VOWEL;
		dfs(_iDepth + 1, _iMaxDepth, _hasL, _vec, _acc * 5, _total);
	}
	else if (check == CONSO)
	{
		_vec[i] = CONSO;
		dfs(_iDepth + 1, _iMaxDepth, _hasL, _vec, _acc * 20, _total);
		dfs(_iDepth + 1, _iMaxDepth, true, _vec, _acc, _total);
		_vec[i] = FILL;
	}
	else if (check == BOTH)
	{
		_vec[i] = VOWEL;
		dfs(_iDepth + 1, _iMaxDepth, _hasL, _vec, _acc * 5, _total);
		_vec[i] = CONSO;
		dfs(_iDepth + 1, _iMaxDepth, _hasL, _vec, _acc * 20, _total);
		dfs(_iDepth + 1, _iMaxDepth, true, _vec, _acc, _total);
		_vec[i] = FILL;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	bool hasL = false;

	string str;
	cin >> str;

	vector<int> vec;
	int iMaxDepth = 0;
	for(auto it : str)
	{
		if (it == 'I' || it == 'E' || it == 'O' || it == 'U' || it == 'A')
			vec.push_back(VOWEL);
		else if (it == '_')
		{
			vec.push_back(FILL);
			iMaxDepth++;
		}
		else
		{
			if (it == 'L')
				hasL = true;
			vec.push_back(CONSO);
		}
	}

	ll total = 0;
	dfs(0, iMaxDepth, hasL, vec, 1, total);

	cout << total;

    return 0;
}
	