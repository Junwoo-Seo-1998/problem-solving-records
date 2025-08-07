#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>
#include <string>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <chrono>
using namespace std;
 
void setup_io()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}
 
constexpr long long twoPow(int pow)
{
    return (long long)1<<pow;
}
 
template<long long N>
  struct Factorial {
      static constexpr long long value = N * Factorial<N - 1>::value;
  };
   
  template<>
  struct Factorial<0> {
      static constexpr long long value = 1;
  };
 
constexpr long long twoPows[10]={twoPow(0), twoPow(1),twoPow(2), twoPow(3), twoPow(4), twoPow(5), twoPow(6), twoPow(7), twoPow(8),twoPow(9)};
 
constexpr long long facto[10]={
    Factorial<0>::value,
    Factorial<1>::value,
    Factorial<2>::value,
    Factorial<3>::value,
    Factorial<4>::value,
    Factorial<5>::value,
    Factorial<6>::value,
    Factorial<7>::value,
    Factorial<8>::value,
    Factorial<9>::value,
};
int N;
int sum=0;
int times=0;
int weights[9];
int checked[9];
void recv(int count, int l, int r)
    {
        if(count==N)
        {
            times++;
            return;
        }
 
        if(l>=sum-l)
        {
            times+=twoPows[N-count]*facto[N-count];
            return;
        }
 
        for(int i=0; i<N; ++i)
        {
            if(checked[i])
                continue;
            checked[i]=true;
            recv(count+1, l+weights[i], r);
 
            if(l>=r+weights[i])
                recv(count+1, l, r+weights[i]);
            checked[i]=false;
        }
    }
 
 
void solve()
{
    sum=0;
    times=0;
    cin>>N;
 
    for(int i=0; i<N; ++i)
    {
        cin>>weights[i];
        sum+=weights[i];
        checked[i]=false;
    }
 
    recv(0,0,0);
    cout<<times;
    cout<<endl;
}
 
int main(void)
{
 
    setup_io();
    int test = 0;
    cin >> test;
    for (int t = 0; t < test; ++t)
    {
        cout<<"#"<<t+1<<" ";
        solve();
    }
 
    return 0;
}