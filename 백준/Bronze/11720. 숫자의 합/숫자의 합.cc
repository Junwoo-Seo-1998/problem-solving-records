#include <iostream>
#include <string>

int main(void)
{
    int n;
    std::cin>>n;
    std::string s;
    std::cin>>s;
    
    long long a=0;
    for(int i=0; i<n; ++i)
    {
        int val=s[i]-'0';
        a+=val;
    }
    std::cout<<a<<std::endl;
    return 0;
}