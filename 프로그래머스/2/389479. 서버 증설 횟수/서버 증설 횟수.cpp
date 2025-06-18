#include <string>
#include <vector>
#include <queue>
//#include <iostream>
using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    queue<int> server;
    
    for(int i=0; i<players.size(); ++i)
    {
        while(!server.empty())
        {
            if(i-server.front()<k)
                break;
            server.pop();
        }
        int serverNeed=players[i]/m-server.size();
        while(serverNeed-->0)
        {
            server.push(i);
            ++answer;
        }
    }
    
    return answer;
}