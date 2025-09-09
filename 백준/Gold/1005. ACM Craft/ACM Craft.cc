#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, K;
int winCondition;
vector<int> adj[100'001];
int deg[1001];
int times[1001];
int timeTook[1001];

inline void init()
{
    cin >> N >> K;

    for (int i = 1; i <= N; ++i)
    {
        cin >> times[i];
        adj[i].clear();
        deg[i] = 0;
        timeTook[i] = 0;
    }

    for (int i = 0; i < K; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        deg[b]++;
    }

    cin >> winCondition;
}

inline void solve()
{
    queue<int> q;

    for (int i = 1; i <= N; ++i)
    {
        if (deg[i] == 0)
        {
            q.push(i);
            timeTook[i] = times[i];
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur == winCondition)
            break;

        for (int next : adj[cur])
        {
            timeTook[next] = max(timeTook[next], timeTook[cur] + times[next]);
            deg[next]--;
            if (deg[next] == 0)
            {
                q.push(next);
            }
        }
    }

    cout << timeTook[winCondition] << '\n';
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; ++tc)
    {
        init();
        solve();
    }

    return 0;
}