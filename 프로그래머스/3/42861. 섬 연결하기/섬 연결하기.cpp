#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int find(std::vector<int>& parents, int target)
{
    if(parents[target]==target)
        return target;
    parents[target]=find(parents, parents[target]);
    return parents[target];
}

void unionParents(std::vector<int>& parents, int a, int b)
{
    a=find(parents, a);
    b=find(parents, b);
    
    if(a<b)
        parents[b]=a;
    else
        parents[a]=b;
}

int solution(int n, vector<vector<int>> costs) {
    
    vector<int> parents;
    parents.reserve(n);
    for(int i=0; i<n; ++i)
        parents.push_back(i);
    
    auto cmp=[](vector<int>& l, vector<int>& r){
        return l[2]<r[2];
    };
    
    std::sort(costs.begin(), costs.end(), cmp);
    int total=0;
    for(auto& cost:costs)
    {
        if(find(parents,cost[0])==find(parents, cost[1]))
            continue;
        total+=cost[2];
        unionParents(parents, cost[0], cost[1]);
    }
    
    return total;
}