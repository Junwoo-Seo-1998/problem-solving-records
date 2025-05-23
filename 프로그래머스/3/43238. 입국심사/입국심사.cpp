#include <string>
#include <vector>
#include <algorithm>
using namespace std;
long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end(), std::less<int>());
    
    auto check=[&](long long mid){
        long long total=0;
        for(int t:times)
        {
            total+=mid/(long long)t;
        }
        return total>=n;
    };
    
    long long l=1;
    long long r=(long long)n*times[times.size()-1];
    while(l<=r)
    {
        long long mid=l+(r-l)/2;
        if(check(mid))
        {
            r=mid-1;
            answer=mid;
        }
        else
        {
            l=mid+1;    
        }
    }
    return answer;
}