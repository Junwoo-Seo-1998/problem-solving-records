#include <string>
#include <vector>
#include <queue>

using namespace std;

int count(vector<vector<bool>>& g, int start)
{
    int count=0;
    
    vector<bool> visited(g.size(), false);
    
    queue<int> q;
    
    q.push(start);
    
    while(!q.empty())
    {
        int toVisit=q.front();
        q.pop();
        if(visited[toVisit])
            continue;
        
        ++count;
        visited[toVisit]=true;
        
        for(int i=1; i<g.size(); ++i)
        {
            if(visited[i])
                continue;
            
            if(g[toVisit][i])
                q.push(i);
        }
    }
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    vector<vector<bool>> g(n+1, vector<bool>(n+1,false));
    
    for(auto& w:wires)
    {
        g[w[0]][w[1]]=true;
        g[w[1]][w[0]]=true;
    }
        
    int answer = std::numeric_limits<int>::max();
    for(auto& w:wires)
    {
        g[w[0]][w[1]]=false;
        g[w[1]][w[0]]=false;
        
        int c1=count(g,w[0]);
        int c2=n-c1;
        
        int c=abs(c1-c2);
        
        answer=min(c, answer);
        
        g[w[0]][w[1]]=true;
        g[w[1]][w[0]]=true;
    }

    return answer;
}