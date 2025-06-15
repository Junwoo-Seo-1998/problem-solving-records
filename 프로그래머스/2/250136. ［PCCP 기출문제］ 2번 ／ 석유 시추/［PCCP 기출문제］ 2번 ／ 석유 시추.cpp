#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> parents;
vector<int> oilSize;

int find(int id)
{
    if(parents[id]==id)
        return id;
    
    return parents[id]=find(parents[id]);
}

void merge(int id1, int id2)
{
    int pid1=find(id1);
    int pid2=find(id2);
    
    if (pid1 != pid2) 
    { 
        parents[pid1] = pid2;
        oilSize[pid2] += oilSize[pid1];
    }
}


int solution(vector<vector<int>> land) {
    
    parents.resize(land.size()*land[0].size());
    oilSize.resize(land.size()*land[0].size(), 1);
    for(int y=0; y<land.size(); ++y)
    {
        for(int x=0; x<land[0].size(); ++x)
        {
            int id=y*land[0].size()+x;
            parents[id]=id;
        }
    }    
    
    for(int y=0; y<land.size(); ++y)
    {
        for(int x=0; x<land[0].size(); ++x)
        {
            if(land[y][x]==1)
            {
                if(y+1<land.size() && land[y+1][x]==1)
                {
                    merge(y*land[0].size()+x, (y+1)*land[0].size()+x);
                }
                
                if(x+1<land[0].size() && land[y][x+1]==1)
                {
                    merge(y*land[0].size()+x, y*land[0].size()+x+1);
                }
            }
        }
    }
    
    int curMax=0;
    
    for(int x=0; x<land[0].size(); ++x)
    {
        set<int> groups;
        for(int y=0; y<land.size(); ++y)
        {
            if (land[y][x] == 1) 
            {
                int id = y*land[0].size() + x;
                int groupId = find(id);
                groups.insert(groupId);
            }
        }
        
        int sum=0;
        for(int id:groups)
        {
            sum+=oilSize[id];
        }
        
        curMax=max(curMax, sum);
    }

    return curMax;
}