	#include <string>
	#include <vector>

	using namespace std;

	bool IsLower(char c)
	{
	    return 'a' <= c && c <= 'z';
	}

	// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
	string solution(string str) {
	    string answer = "";
	    string wrong = "invalid";

	    vector<vector<int>> cIdxs(26);

	    int idx = 0;
	    for (auto c : str)
	    {
	        if(IsLower(c))
				cIdxs[c - 'a'].push_back(idx);
	        idx++;
	    }

	    // 1개 일 경우 무조건 M, 2개일 경우 무조건 FB, 3개 이상일 경우 무조건 M
	    int safe = -1;
	    for (int i = 0; i < str.length();)
	    {
	        if (IsLower(str[i]))
	        {
	            // FB
	            if (cIdxs[str[i] - 'a'].size() == 2)
	            {
	                if( answer.length() != 0 && answer.back() != ' ')
						answer += ' ';
	                int cur = i;
	                // yes M
	                if (IsLower(str[i + 2]) && str[i + 2] != str[i])
	                {
	                    if (IsLower(str[i + 1])) return wrong;
	                    else answer += str[i + 1];

	                    cur = i + 2;
	                    int j = cur;
	                    bool toggle = false;
	                    while (cur <= cIdxs[str[j] - 'a'].back())
	                    {
	                        if (IsLower(str[cur]) == toggle)
	                            return wrong;
							toggle = !toggle;
	                        if (IsLower(str[cur]) && str[j] != str[cur])
	                            return wrong;
	                        if (IsLower(str[cur]))
	                        {
								answer += str[cur + 1];
	                        }
	                        cur++;
	                    }
	                    int nxt = cIdxs[str[j] - 'a'].back() + 2;
	                    if (str[nxt] != str[i]) return wrong;
	                    safe = nxt;
	                    i = nxt + 1;
	                    answer += ' ';
	                }
	                else
	                {
	                    cur++;
	                    while (cur < cIdxs[str[i] - 'a'].back())
	                    {
	                        if (IsLower(str[cur])) return wrong;
	                        answer += str[cur];
	                        cur++;
	                    }
	                    safe = cur;
	                    i = cur + 1;
	                    answer += ' ';
	                }
	            }
	            // M
	            else
	            {
					if(answer.length() != 0 && isupper(answer.back()))
					{
						char tmp = answer.back();
						answer.pop_back();
						if (!answer.empty() && answer.back() != ' ')
							answer += ' ';
						answer.push_back(tmp);
					}

	                int cur = i;
	                bool toggle = false;
	                if (safe >= cur - 1) return wrong;
	                while (cur <= cIdxs[str[i] - 'a'].back())
	                {
	                    if (IsLower(str[cur]) == toggle)
	                        return wrong;
	                    toggle = !toggle;
	                    if (IsLower(str[cur]) && str[i] != str[cur])
	                        return wrong;

	                    if (IsLower(str[cur]))
	                    {
	                        answer += str[cur + 1];
	                    }
	                    cur++;
	                }
	                answer += ' ';
	                safe = cIdxs[str[i] - 'a'].back() + 1;
	                i = cIdxs[str[i] - 'a'].back() + 2;
	            }
	        }
	        else
	        {
	            answer += str[i];
	            i++;
	        }
	    }

	    if (answer.back() == ' ')
	        answer.pop_back();
	    return answer;
	}

	int main()
	{
	    auto a = solution("aBasD");
	    return 0;
	}

	//"HaEaLaLaObWORLDb"	"HELLO WORLD"
	//"SpIpGpOpNpGJqOqA"	"SIGONG JOA"
	//"AxAxAxAoBoBoB"	"invalid"
	//"aAaAaAABBB"	"invalid"
	//"aAaAABBB"	"A AABBB"
	//"aAAAbBBBb"	"invalid"
	//"AaAaAbAbAb"	"invalid"
	//"AaAaAbAbAbA"	"A A AAAA"
	//	"AaAaAaAbAbAbA"	"invalid"
	//	"aHbEbLbLbacWdOdRdLdDc"	"invalid"
	//	"AaBcBcBaBdBgBdeFFeBBBBsBScS"	"invalid"
	//	"AaBcBcBaBdBgBdeFFeBBBBsBStS"	"A BBB BB FF BBB BB SS"
	//	"HaEaLaLaObWORLDbSpIpGpOpNpGJqOqAdGcWcFcDdeGfWfLeoBBoAAAAxAxAxAA"	"HELLO WORLD SIGONG J O A GWFD GWL BB AAA AAAA A"
	//	"AababB"	"invalid"
	//	"AabCbaB"	"invalid"
	//	"AabCbCbCaB"	"invalid"
	//	"AaCbUaCbCbCB"	"invalid"
	//	"AaAaAcA"	"A A AA"
	//	"aBasD"	"invalid"