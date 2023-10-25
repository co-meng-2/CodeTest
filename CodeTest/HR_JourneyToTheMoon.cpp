#include <vector>
using std::vector;

int p[100000]{};

int Find(int n)
{
    if (p[n] < 0) return n;
    return p[n] = Find(p[n]);
}

bool Union(int parent, int child)
{
    parent = Find(parent);
    child = Find(child);

    if (parent == child) return false;

    p[parent] += p[child];
    p[child] = parent;
    return true;
}

long long journeyToMoon(int n, vector<vector<int>> astronauts)
{
    std::fill(p, p + n, -1);

    for (auto astronaut : astronauts)
    {
        Union(astronaut[0], astronaut[1]);
    }

    long long ans = 0;
    vector<int> nums;
    for (int i = 0; i < n; ++i)
    {
        if (p[i] < 0)
            nums.push_back(-p[i]);
    }

    int sub = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        sub += nums[i];
        ans += nums[i] * (n - sub);
    }

    return ans;
}