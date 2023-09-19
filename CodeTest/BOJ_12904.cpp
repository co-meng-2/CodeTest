#include <iostream>
#define fastio std::ios_base::sync_with_stdio(false);\
cin.tie(NULL);
using std::cin;
using std::cout;

#include <string>
using std::string;

// 문자열 ST가주어짐 S를 T로 바꾸는 게임
// 문자열은 A와 B로만 구성
// 1. 문자열의 뒤에 A를 추가
// 2. 문자열을 뒤집고 뒤에 B를 추가
// S를 T로 바꿀 수 있으면 1아니면 0을 출력
// S 1 - 999 T 2 - 1000
// T의 길이가 S의 길이보다 크다.

// 풀이 방법
// Brute -> 2^(T-S) 불가능
// 겹치는 문자열이 같은 레벨에 존재
// BFS로 걸러준다? or backtracking?

// backtracking A와 B의 갯수 2^500
// BFS 같은 모양

void Sub(string& str)
{
	str.pop_back();
}

void SubReverse(string& str)
{
	str.pop_back();
	string tmp;
	for(auto it = str.rbegin(); it != str.rend(); ++it)
		tmp.push_back(*it);
	str = tmp;
}

int main()
{
	string S, T;
	cin >> S;
	cin >> T;

	while(T.size() > S.size())
	{
		if (T.back() == 'A')
			Sub(T);
		else if (T.back() == 'B')
			SubReverse(T);
	}

	bool ret = true;
	for(int i = 0; i < S.size(); ++i)
	{
		if(T[i] != S[i])
		{
			ret = false;
			break;
		}
	}

	cout << ret;

	return 0;
}

// 30분