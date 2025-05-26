#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> trucks;
    for(int w:truck_weights)
        trucks.push(w);
    
    queue<int> bridge;
    for(int i=0; i<bridge_length; ++i)
        bridge.push(0);
    
    int w=weight;
    while(!trucks.empty())
    {
        int currentW=bridge.front();
        bridge.pop();
        
        w+=currentW;
            
        answer++;
        
        if(trucks.front()<=w)
        {
            w-=trucks.front();
            bridge.push(trucks.front());
            trucks.pop();
            continue;
        }

        bridge.push(0);   
    }
    
    return answer+bridge_length;
}