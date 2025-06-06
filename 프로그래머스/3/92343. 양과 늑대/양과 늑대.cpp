#include <string>
#include <vector>
#include <functional>
#include <iostream>
#include <bitset>
using namespace std;

int solution(vector<int> info, vector<vector<int>> edges) {
    
    
    vector<int> g[17];
    for(auto& e:edges)
    {
        g[e[0]].push_back(e[1]);
    }
    
    int max_sheep=-1;
    function<void(int,int,int,bitset<17>)> recv=[&](int cur, int wolf, int sheep, bitset<17> toVisit)
    {
            
            if(info[cur]==0)
            {
                sheep++;
            }
            else
            {
                wolf++;
            }
            
            if(wolf>=sheep)
                return;
            
            toVisit[cur]=false;
            for(int i=0; i<g[cur].size(); ++i)
                toVisit[g[cur][i]]=true;
        
            max_sheep=max(max_sheep, sheep);
            
            for(int i=0; i<toVisit.size(); ++i)
            {
                if(toVisit[i])
                    recv(i, wolf, sheep, toVisit);
            } 
        
    };
    
    recv(0, 0, 0, {1, });
    return max_sheep;
}