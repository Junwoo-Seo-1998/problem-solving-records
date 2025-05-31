#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <limits>
using namespace std;
bool check(string& left, string& right)
{
    int count=0;
    
    for(int i=0; i<left.size(); ++i)
    {
        if(left[i]!=right[i])
        {
            ++count;
            if(count>1)
                return false;
        }
    }
    
    return count==1;
}
int solution(string begin, string target, vector<string> words) {
    if(std::find(words.begin(), words.end(), target)==words.end())
        return 0;
    int count=numeric_limits<int>::max();
    vector<bool> visited(words.size(), false);
    function<void(int, int)> dfs=[&](int cur, int step){
        if(step>count)
            return;
        
        if(words[cur]==target)
        {
            count=step;
            return;
        } 
            
        for(int i=0; i<words.size(); ++i)
        {   
            if(visited[i])
                continue;
            
            if(check(words[cur], words[i]))
            {
                visited[i]=true;
                dfs(i, step+1);
                visited[i]=false;
            }
        }
    };
    
    for(int i=0; i<words.size(); ++i)
    {   
        if(visited[i])
            continue;
        if(check(begin, words[i]))
        {
            visited[i]=true;
            dfs(i, 1);
            visited[i]=false;
        }
    }
    return count;
}