#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    std::sort(rocks.begin(), rocks.end(), std::less<int>());
    auto check=[&](int val){
        int deleted=0;
        
        int start=0;
        for(int i=0; i<rocks.size(); ++i)
        {
            if(rocks[i]-start<val)
            {
                deleted++;
            }
            else
            {
                start=rocks[i];
            }
        }
        
        if(distance-start<val)
            deleted++;
        return deleted<=n;
    };
    
    int left = 0;
    int right= distance;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(check(mid))
        {
            left=mid+1;
            answer=mid;
        }
        else
        {
            right=mid-1;
        }
    }
    
    return answer;
}