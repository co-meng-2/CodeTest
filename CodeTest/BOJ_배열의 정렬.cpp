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
#include <memory.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair < int, ll > ;
using tiii = tuple<int, int, int>;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

const int INF = 0x3f3f3f3f;

int n, m;
int arr[8];
int change[8][8]{};
ll correctNum;

unordered_map<ll, int> visited;

bool visited2[10][10][10][10][10][10][10][10]{};

ll Hash(vector<int>& nums)
{
	ll mul = 1;
	ll ret = 0;
	for(int i = n - 1; i >= 0; --i)
	{
		ret += mul * nums[i];
		mul *= 10;
		if (nums[i] == 10)
			mul *= 10;
	}
	return ret;
}

int main()
{
	fastio;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		arr[i]--;
	}
		

	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int s, d, w;
		cin >> s >> d >> w;
		s--;
		d--;
		if (change[s][d] == 0)
			change[s][d] = w;
		else
			change[s][d] = min(change[s][d], w);
	}

	struct tInfo
	{
		int w;
		int nums[8];

		tInfo(int _w, int* _nums)
		{
			w = _w;
			memcpy(nums, _nums, sizeof(nums));
		}

		bool operator>(const tInfo& rhs)
		{
			return w > rhs.w;
		}
	};

	priority_queue<tInfo, vector<tInfo>, greater<>> PQ;
	int correct[8];
	memcpy(correct, arr, sizeof(arr));
	copy(arr, arr + n, correct);
	sort(correct, correct + n);
	PQ.push( tInfo{ 0, arr });

	while (!PQ.empty())
	{
		auto [cw, nums] = PQ.top();
		PQ.pop();

		if (visited2[nums[0]][nums[1]][nums[2]][nums[3]][nums[4]][nums[5]][nums[6]][nums[7]]) continue;
		visited2[nums[0]][nums[1]][nums[2]][nums[3]][nums[4]][nums[5]][nums[6]][nums[7]] = true;

		bool bFind = true;
		for (int i = 0; i < n; ++i)
		{
			if (correct[i] != nums[i])
			{
				bFind = false;
				break;
			}
		}

		if(bFind)
		{
			cout << cw;
			return 0;
		}

		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
			{
				if (change[i][j] == 0) continue;

				swap(nums[i], nums[j]);
				PQ.push({ cw + change[i][j], nums });
				swap(nums[i], nums[j]);
			}
	}

	cout << -1;

	return 0;
};


// S : 7 20
// U : 
// T : 
// C :
// Total :
