#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>
#include <utility>
#include <set>
#include <limits>
#include<queue>
using namespace std;

int main(int, char**){
    int T;
    cin>>T;
    for(int t=0; t<T; ++t)
    {
        int N;
        cin>>N; 

        int M;
        cin>>M;

        vector<pair<int, bool>> arr(N);
        queue<pair<int, int>>q;
        for(int i=0; i<N; ++i)
        {
            int temp;
            cin>>temp;
            q.push({temp, i});
            arr[i]={temp, false};
        }
        int count=0;
        while(!q.empty())
        {
            pair<int, int> p=q.front();
            q.pop();

            if(any_of(arr.begin(), arr.end(), [&](pair<int, bool>& e){
                return e.first>p.first && e.second==false;
            }))
            {
                q.push(p);
            }
            else{
                arr[p.second].second=true;
                count++;
                if(p.second==M)
                {
                    cout<<count<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}