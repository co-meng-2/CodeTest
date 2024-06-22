#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 절삭 때문에 이렇게 풀면 안됨
void dfs(int cur, int p, vector<vector<int>>& adjList, vector<int>& ret)
{
	for(auto it : adjList[cur])
	{
        dfs(it, cur, adjList, ret);
	}

    if(p != -1)
		ret[p] += ret[cur] / 10;
    ret[cur] -= ret[cur] / 10;
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> sellers, vector<int> amount) {
    vector<int> answer;


    unordered_map<string, int> mapIdx;
    for (int i = 0; i < enroll.size(); ++i)
    {
        mapIdx.insert({ enroll[i], i });
    }

    vector<vector<int>> adjList(enroll.size());
    vector<int> tops;
    for(int i = 0; i < referral.size(); ++i)
    {
        auto fd = mapIdx.find(referral[i]);
        if (fd != mapIdx.end())
        {
            // 추천으로 들어온 애를 부모가 들고 있게끔
            adjList[fd->second].push_back(i);
        }
        else
            tops.push_back(i);
    }

    //vector<int> ret(enroll.size());
    //for(int i = 0; i < sellers.size(); ++i)
    //{
    //    int total = 100 * amount[i];
    //    ret[mapIdx.find(sellers[i])->second] = total;
    //}

    //for (auto top : tops)
    //    dfs(top, -1, adjList, ret);

    vector<int> refList(enroll.size(), -1);

    for (int i = 0; i < referral.size(); ++i)
    {
        auto fd = mapIdx.find(referral[i]);
        if (fd != mapIdx.end())
            refList[i] = fd->second;
    }

    vector<int> ret(enroll.size(), 0);
    for (int i = 0; i < sellers.size(); ++i)
    {
        int idx = mapIdx.find(sellers[i])->second;
        int total = 100 * amount[i];
        ret[idx] += total;
        while (total > 0)
        {
            ret[idx] -= total / 10;
            if (refList[idx] == -1) break;
            ret[refList[idx]] += total / 10;
            total /= 10;
            idx = refList[idx];
        }
    }

    answer = ret;

    return answer;
}

int main()
{
    solution({ "john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young" }, { "-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward" }, { "young", "john", "tod", "emily", "mary"
        }, {12, 4, 2, 5, 10
});
    return 0;
}