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
// ���λ縸���� �����ϸ� ddd�� ���� �Ұ���
// �տ��� �ϳ��� �ڸ��鼭 �����ؾ���
// ���̻�� F�Լ��� ���� �ڵ����� �� �κ��� �߸��Ƿ� �ڸ� �ڸ��� ���� Pass
// F[x]�� ���̰� x�� �ڱ� �ڽ��� �ƴ� ���� �κ� ���ڿ��� ã�� �����Ƿ� �� �߿� ���� ū ���� return �ϸ� �ȴ�.

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