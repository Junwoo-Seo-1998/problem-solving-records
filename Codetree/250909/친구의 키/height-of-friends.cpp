#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//dfs로 위상정렬 하는거 연습해보는 용


int n, m;
int a[100000], b[100000];

bool visited[100'001];
vector<int> edge[100'001];

stack<int> sorted;

void dfs(int cur)
{
    for(int next:edge[cur])
    {
        if(visited[next]) continue;
        visited[next]=true;
        dfs(next);
    }

    sorted.push(cur);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
    }

    for(int i=0; i<m; ++i)
    {
        edge[a[i]].push_back(b[i]);
    }

    for(int i=1; i<=n; ++i)
    {
        if(visited[i]!=true)
        {
            visited[i]=true;
            dfs(i);
        }
    }


    while(!sorted.empty())
    {
        cout<<sorted.top()<<' ';
        sorted.pop();
    }

    return 0;
}