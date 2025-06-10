#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4, 0);
    
    unordered_map<int, pair<int, int>> inOut;
    
    for(auto& e:edges)
    {
        int from=e[0];
        int to=e[1];
        inOut[from].second++;
        inOut[to].first++;
    }
    
    for(auto& p:inOut)
    {
        auto [in, out]=p.second;
        
        if(out==0)
            answer[2]++;
        else if(out==1)
            continue;
        else if(out==2)
        {
            if(in==0)
            {
                answer[0]=p.first;
                continue;
            }
            answer[3]++;
        }
        else
        {
            if(in==0)
                answer[0]=p.first;
        }
    }
    
    answer[1]=inOut[answer[0]].second-(answer[2]+answer[3]);
    return answer;
}