#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = -1;
    
    auto check=[&](long long time)->bool
    {
        long long totalMax=0;
        long long gMax=0;
        long long sMax=0;
        
        for(int i=0; i<w.size(); ++i)
        {
            long long count=time / (2LL * t[i]);
            if(time % (2LL * t[i]) >= t[i])
                ++count;
            
            long long possible=count*w[i];
            totalMax+=min<long long>(possible, (long long)g[i]+(long long)s[i]);
            gMax+=min<long long>(possible, g[i]);
            sMax+=min<long long>(possible, s[i]);
        }
        
        return totalMax>=a+b && gMax>=a && sMax>=b;
    };
    
    long long left=0;
    long long right=400000000000000LL;
    while(left<=right)
    {
        long long mid=(left+right)/2;
        
        if(check(mid))
        {
            answer=mid;
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }
    
    return answer;
}