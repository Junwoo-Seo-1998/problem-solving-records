#include <string>
#include <vector>
#include <functional>
#include <iostream>
using namespace std;

vector<int> solution(int n, vector<int> info) {
    vector<int> answer={-1,};
    
    vector<int> history(info.size(), 0);
    
    int point=1;
    int lastLowestPos=0;
    function<void(int, int, int, int)> dfs=[&](int current, int lion, int peach, int ammo)
    {
        if(current==11)
        {
            if(ammo>0)
                history[10]=ammo;
            
            if(lion-peach>point)
            {
                point=lion-peach;
                answer=history;
            }
            else if((lion-peach) == point)
            {
                for (int i = 10; i >= 0; --i)
                {
                    if(answer[i]<history[i])
                    {
                        answer=history;
                        break;
                    }
                    
                    if (history[i] < answer[i])
                        break;
            
                }
            }
            
            if(ammo>0)
                history[10]=0;
            
            return; 
        }
        
        //rion win
        if(info[current]<ammo) 
        {
            history[current]=info[current]+1;
            dfs(current+1, lion+10-current, peach, ammo-info[current]-1);
            history[current]=0;
        }
        
        //rion lose
        if(info[current])
            dfs(current+1, lion, peach+10-current, ammo);
        else //no winner
            dfs(current+1, lion, peach, ammo);
    };
    
    dfs(0, 0, 0, n);
    return answer;
}