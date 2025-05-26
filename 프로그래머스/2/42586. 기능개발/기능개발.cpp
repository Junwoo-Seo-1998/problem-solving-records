#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int last=-1;
    int count=0;
    for(int i=0; i<progresses.size(); ++i)
    {
        int takes=ceil((100.f-progresses[i])/speeds[i]);
        if(last==-1)
        {
            last=takes;
            count=1;
            continue;
        }
        else if(last<takes)
        {
            last=takes;
            answer.push_back(count);
            count=1;
        }
        else
        {
            count++;
        }
    }
    answer.push_back(count);
    return answer;
}