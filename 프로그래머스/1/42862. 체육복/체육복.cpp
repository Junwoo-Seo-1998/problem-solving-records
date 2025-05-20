#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    int answer = n-lost.size();
    for (int& i : lost)
    {
        auto it = find(reserve.begin(), reserve.end(), i);
        if (it != reserve.end())
        {
            reserve.erase(it);
            i = -1;
            answer++;
        }
    }
    
    
    for(int l=0; l<lost.size(); ++l)
    {
        if(lost[l]==-1)
            continue;
        for(int r=0; r<reserve.size(); ++r)
        {
            if( reserve[r]!=-1 && (lost[l]-1 == reserve[r] || lost[l]+1==reserve[r]))
            {
                reserve[r]=-1;
                answer++;
                break;
            }
        }
    } 
    return answer;
}