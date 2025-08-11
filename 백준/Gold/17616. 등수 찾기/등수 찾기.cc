#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;
int N;

unordered_map<int, vector<int>> front;
unordered_map<int, vector<int>> back;

int getFrontCount(int me)
{
    queue<int> q;
    vector<bool> v(N+1, false);
    q.push(me);
    v[me]=true;
    int count=0;
    while(!q.empty())
    {
        auto f=q.front();
        q.pop();
        for(auto i:front[f])
        {
            if(v[i]) continue;
                v[i]=true;
            count++;
            q.push(i);
        }
    }
    return count;
}

int getBackCount(int me)
{
    queue<int> q;
    vector<bool> v(N+1, false);
    v[me]=true;
    q.push(me);
    int count=0;
    while(!q.empty())
    {
        auto f=q.front();
        q.pop();
        for(auto i:back[f])
        {
            if(v[i]) continue;
            v[i]=true;
            count++;
            q.push(i);
        }
    }
    return count;
}

void solve()
{
    cin>>N;
    int M, X;
    cin>>M>>X;

    for(int i=0; i<M; ++i)
    {
        int a, b;
        cin>>a>>b;
        front[b].push_back(a);
        back[a].push_back(b);
    }
    cout<<getFrontCount(X)+1<<endl;
    cout<<N-getBackCount(X)<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int T;
    // cin >> T;
    // for (int t = 1; t <= T; ++t)
    // {
    //     cout << "#" << t << " " << solve() << "\n";
    // }
    solve();
    return 0;
}