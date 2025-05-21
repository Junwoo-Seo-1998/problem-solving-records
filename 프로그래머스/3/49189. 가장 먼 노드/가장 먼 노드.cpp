#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    unordered_map<int, vector<int>> map;
    
    for(auto& e: edge)
    {
        map[e[0]-1].push_back(e[1]-1);
        map[e[1]-1].push_back(e[0]-1);
    }
    
    auto func=[](pair<int, int>& l, pair<int, int>&r){  
        if(l.second==r.second)
            return l.first>r.first;
        return l.second>r.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(func)> q(func);
    
    vector<int> dist(n, numeric_limits<int>::max());
    dist[0]=0;
    q.push({0, 0});
    while(!q.empty())
    {
        auto top=q.top();
        q.pop();
        
        if(top.second>dist[top.first])
            continue;
        
        for(int neighbor:map[top.first])
        {
            if(dist[neighbor]>top.second+1)
            {
                dist[neighbor]=top.second+1;
                q.push({neighbor, top.second+1});
            }
        }
    }
    int count=0;
    int curMax=-1;
    for (int i : dist)
{
    if (i > curMax)
    {
        curMax = i;
        count = 1;  // 처음 하나 발견!
    }
    else if (i == curMax)
    {
        count++;
    }
}
    
    
    return count;
}