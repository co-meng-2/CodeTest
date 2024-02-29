#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

int main()
{
	fastio;

	int N, M;
	cin >> N >> M;

	vector<int> nums(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> nums[i];
	}

	int s = 0;
	int e = 0;
	long long sum = 0;
	int cnt = 0;
	while (true)
	{
		if (sum < M)
		{
			e++;
			if (e > nums.size()) break;
			sum += nums[e-1];
		}
		else if(sum == M)
		{
			cnt++;
			sum -= nums[s];
			s++;	
		}
		else
		{
			sum -= nums[s];
			s++;
		}
	}

	cout << cnt;

	return 0;
}


// S : 
// U : 
// T : 
// C :
// Total :