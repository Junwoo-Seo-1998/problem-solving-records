#include <string>
#include <vector>
#include <functional>
using namespace std;

bool isPrime(long long val)
{
    if(val<=1)
        return false;
    
    for(long long i=2; i*i<=val; ++i)
        if(val % i == 0)
            return false;
    
    return true;
}

int solution(int n, int k) {
    vector<int> arr;
    
    function<void(long long)> getArr=[&](long long current)
    {
        if(current==0)
            return;
        
        getArr(current/k);
        arr.push_back(current%k);
    };
    
    getArr(n);
    
    int answer = 0;
    long long sum=0;
    for(int i=0; i<arr.size(); ++i)
    {
        if(arr[i]!=0)
        {
            sum*=10;
            sum+=arr[i];
        }
        else
        {
            if(sum!=0)
            {
                if(isPrime(sum))
                    answer++;
            }
            sum=0;
        }
    }
    if(sum!=0)
    {
        if(isPrime(sum))
            answer++;
    }
    return answer;
}