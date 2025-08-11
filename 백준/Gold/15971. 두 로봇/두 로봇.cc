#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <unordered_map>
using namespace std;
int N;
int A, B;
struct info
{
    int cur=0;
    int maxDist=0;
    int pathSum=0;
};

unordered_map<int, vector<pair<int, int>>> map;
int solve()
{
    cin>>N;
    cin>>A>>B;

    for(int i=0; i<N-1; ++i)
    {
        int from, to, dist;
        cin>>from>>to>>dist;
        map[from].emplace_back(pair<int,int>{to, dist});
        map[to].emplace_back(pair<int,int>{from, dist});
    }
    queue<info> q;
    vector<bool> v(N+1, false);
    q.push({A, 0, 0});
    v[A]=true;
    while(!q.empty())
    {
        auto p=q.front();
        q.pop();
        int cur=p.cur;

        if(cur==B)
        {   
            return p.pathSum-p.maxDist;
        }

        for(auto& to_dist:map[cur])
        {
            if(v[to_dist.first])
                continue;
            v[to_dist.first]=true;
            q.push({to_dist.first, max(p.maxDist, to_dist.second), p.pathSum+to_dist.second});
        }
    }

    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<solve();
    return 0;
}