#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL)
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>
#include <deque>
using std::deque;

#include <string>
using std::string;



// abdddaadddba
// 접두사만으로 판정하면 ddd를 판정 불가능
// 앞에서 하나씩 자르면서 진행해야함
// 접미사는 F함수에 의해 자동으로 뒤 부분이 잘리므로 뒤를 자르는 경우는 Pass
// F[x]는 길이가 x인 자기 자신이 아닌 같은 부분 문자열을 찾은 것으므로 이 중에 가장 큰 것을 return 하면 된다.

int Failure(deque<char>& S)
{
	vector<int> f(S.size(), 0);

	int Max = 0;
	int j = 0;
	for (int i = 1; i < S.size(); i++)
	{
		while (j > 0 && S[i] != S[j]) 
			j = f[j - 1];
		if (S[i] == S[j])
		{
			f[i] = ++j;
			Max = std::max(Max, f[i]);
		}
	}
	return Max;
}

int main()
{
	fastio;

	string S;
	cin >> S;
	deque<char> dq;

	for (auto c : S)
		dq.push_back(c);

	int Max = 0;
	while(!dq.empty())
	{
		Max = std::max( Failure(dq), Max);
		dq.pop_front();
	}

	cout << Max;

	return 0;
}


// S : 1:41
// U : 1:43
// T : 2:06
// C : 2:28
// Total : 47min