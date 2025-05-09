#include<utility>
#include<queue>
#include<vector>

using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    int ymax=maps.size();
    int xmax=maps[0].size();
    vector<vector<bool> > visited(ymax, std::vector<bool>(xmax, false));
    //maps[ymax-1][xmax-1]=2;
    
    std::queue<std::pair<std::pair<int, int>, int>> q;
    
    
    
    q.push({{0,0}, 0});
    //int count=0;
    while(!q.empty())
    {
        auto [coord, count]=q.front();
        auto [x,y]=coord;
        q.pop();
        
                
        if(x<0 || x>=xmax)
            continue;
        if(y<0 || y>=ymax)
            continue;
        
        if(visited[y][x])
            continue;
        if(maps[y][x]==0)
            continue;
        
        visited[y][x]=true;
        count++;
                
        if(x==xmax-1 && y==ymax-1)
            return count;

        q.push({{x+1, y}, count});
        q.push({{x-1, y}, count});
        q.push({{x, y+1}, count});
        q.push({{x, y-1}, count});
    }
    
    
    
    return  -1;
}