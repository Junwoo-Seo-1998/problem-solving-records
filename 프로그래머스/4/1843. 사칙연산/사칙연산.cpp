#include <vector>
#include <string>
#include <functional>
#include <limits>
using namespace std;

int solution(vector<string> arr)
{
    constexpr int min_val=numeric_limits<int>::min();
    constexpr int max_val=numeric_limits<int>::max();
    vector<vector<pair<int, int>>> dp(arr.size(), vector<pair<int, int>>(arr.size(), {max_val, min_val}));
    vector<vector<bool>> v(arr.size(), vector<bool>(arr.size(), false));
    
    function<void(int,int)> dfs=[&](int start, int end){
        if(v[start][end])
            return;
        else if(start==end)
        {
            int val=stoi(arr[start]);
            dp[start][end]={val, val};
            return;
        }

        int resMax=min_val;
        int resMin=max_val;
        for(int i=start+1; i<end; ++i)
        {
            if(arr[i]=="+")
            {
                dfs(start, i-1);
                dfs(i+1, end);
                resMax=max(resMax, dp[start][i-1].second+dp[i+1][end].second);
                resMin=min(resMin, dp[start][i-1].first+dp[i+1][end].first);
            }
            else if(arr[i]=="-")
            {
                dfs(start, i-1);
                dfs(i+1, end);
                resMax=max(resMax, dp[start][i-1].second-dp[i+1][end].first);
                resMin=min(resMin, dp[start][i-1].first-dp[i+1][end].second);
            }
        }
        
        dp[start][end]={resMin, resMax};
        v[start][end]=true;
    };
    dfs(0, arr.size()-1);
    return dp[0][arr.size()-1].second;
}