#include <string>
#include <vector>
#include <functional>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    vector<bool> visited(dungeons.size(), false);
    function<void(int,int,int)> dfs=[&](int tired, int idx, int times){
        if(dungeons[idx][0]>tired)
        {
            return;
        }
        
        tired-=dungeons[idx][1];
        ++times;
        answer=max(times, answer);
        for(int i=0; i<dungeons.size(); ++i)
        {
            if(visited[i])
                continue;
            
            visited[i]=true;
            dfs(tired, i, times);
            visited[i]=false;
        }
    };
    
    for(int i=0; i<dungeons.size(); ++i)
    {
        visited[i]=true;
        dfs(k, i, 0);
        visited[i]=false;
    }
    return answer;
}