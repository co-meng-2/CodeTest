#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strs) {
    vector<string> answer(strs.size());

    int i = 0;
    for(auto& s : strs)
    {
        int cnt = 0;
        string st;
        // 
        for (auto& c : s)
        {
            st.push_back(c);

            if (st.size() >= 3 && st[st.size() - 3] == '1' && st[st.size() - 2] == '1' && st[st.size() - 1] == '0')
            {
                for(int j = 0; j < 3; ++j)
                {
                    st.pop_back();
                }
                cnt++;
            }
        }

        auto it = st.rfind('0');
        // 0이 없다
        if(it == string::npos)
        {
            for(int j = 0; j < cnt; ++j)
            {
                answer[i].append("110");
            }
            answer[i].append(st);
        }
        else
        {
            answer[i].append(st, 0, it + 1);
            for (int j = 0; j < cnt; ++j)
            {
                answer[i].append("110");
            }
            answer[i].append(st, it + 1, st.size() - (it + 1));
        }
        i++;
    }

    return answer;
}

int main()
{
    vector<string> strs;
    strs.push_back("100111100");
    strs.push_back("100111100");
    strs.push_back("0111111010");
    auto k = solution(strs);
    return 0;
}
