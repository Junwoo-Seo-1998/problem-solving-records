#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>
using namespace std;


class doubleHeap
{
public:
    void push(int val)
    {
        dead[val]++;
        maxQueue.push(val);
        minQueue.push(val);
    }
    
    bool popMax(int& toRet)
    {  
        while(!maxQueue.empty())
        {
            toRet=maxQueue.top();
            maxQueue.pop();
            if(dead[toRet]!=0)
            {
                dead[toRet]--;
                return true;
            }
        }
        
        return false;
    }
    
    bool popMin(int& toRet)
    {
        while(!minQueue.empty())
        {
            toRet=minQueue.top();
            minQueue.pop();
            if(dead[toRet]!=0)
            {
                dead[toRet]--;
                return true;
            }
        }
        
        return false;
    }
    
    int maxTop()
    {
        int val=0;
        if(popMax(val))
        {
            maxQueue.push(val);
            dead[val]++;
            return val;
        }
        return 0;
    }
    
    int minTop()
    {
        int val=0;
        if(popMin(val))
        {
            minQueue.push(val);
            dead[val]++;
            return val;
        }
        return 0;
    }
private:
    priority_queue<int, vector<int>, less<int>> maxQueue;
    priority_queue<int, vector<int>, greater<int>> minQueue;
    
    unordered_map<int, int> dead;
};

vector<int> solution(vector<string> operations) {
    doubleHeap dh;
    for(auto& c: operations)
    {
        int num=stoi(c.substr(2, 2+c.size()));
        if(c[0]=='I')
        {
            dh.push(num);
        }
        else
        {
            int val=0;
            if(num==1)
                dh.popMax(val);
            else
                dh.popMin(val);
        }
    }
    
    //vector<int> answer;
    
    return {dh.maxTop(), dh.minTop()};
}