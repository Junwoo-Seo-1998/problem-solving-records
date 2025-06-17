#include <string>
#include <vector>
#include <iterator>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    int x=0 , y=0;
    for(; y<park.size(); ++y)
    {
        if(auto it=park[y].find('S'); it!=string::npos)
        {
            x=it;
            break;
        }
    }
    for(auto& s:routes)
    {
        bool fail=false;
        int totalDist=s[2]-'0';
        int tempX=x, tempY=y;
        for(; totalDist!=0; --totalDist)
        {
        switch(s[0])
        {
            case 'N': tempY+=-1; break;
            case 'S': tempY+=1; break;
            case 'W': tempX+=-1; break;
            case 'E': tempX+=1; break; 
        }
        
        fail |= park.size()<=tempY || tempY<0 || park[0].size()<=tempX || tempX<0 || park[tempY][tempX]=='X';
            
        if(fail)
            break;
        }
        
        if(fail)
            continue;
        
        x=tempX;
        y=tempY;
    }
    
    return {y, x};
}