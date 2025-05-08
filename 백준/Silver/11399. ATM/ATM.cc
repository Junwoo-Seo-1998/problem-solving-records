#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
int main(void)
{
    int n=0;
    std::vector<int> arr;
    std::cin>>n;
    
    if(n<=0)
        return 0;
    
    for(int i=0; i<n; ++i)
    {
        int val=0;
        std::cin>>val;
        arr.push_back(val);
    }
    
    std::sort(arr.begin(), arr.end());
    int s=arr[0];
    for(int i=1; i<arr.size(); ++i)
    {
        arr[i]+=arr[i-1];
        s+=arr[i];
    }
    std::cout<<s<<std::endl;
    return 0;
}