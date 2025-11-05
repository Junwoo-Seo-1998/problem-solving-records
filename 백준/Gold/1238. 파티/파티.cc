#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

int N, M, X;
vector<pair<int, int>> adj[1001];
vector<pair<int, int>> rev_adj[1001];
const int INF = numeric_limits<int>::max();

void input()
{
    cin >> N >> M >> X;

    for (int i = 0; i < M; ++i)
    {
        int from, to, dist;
        cin >> from >> to >> dist;
        adj[from].push_back({ to, dist });
        rev_adj[to].push_back({ from, dist });
    }
}

vector<int> dijkstra(int start, const vector<pair<int, int>> graph[])
{
    vector<int> dist(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty())
    {
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if (currentDist > dist[currentNode])
            continue;

        for (auto& edge : graph[currentNode])
        {
            int nextNode = edge.first;
            int edgeWeight = edge.second;

            if (dist[nextNode] > currentDist + edgeWeight)
            {
                dist[nextNode] = currentDist + edgeWeight;
                pq.push({ dist[nextNode], nextNode });
            }
        }
    }
    return dist;
}

void solve()
{
    vector<int> goToPartyDist = dijkstra(X, rev_adj);
    vector<int> returnHomeDist = dijkstra(X, adj);

    int maxTime = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (goToPartyDist[i] != INF && returnHomeDist[i] != INF)
        {
            maxTime = max(maxTime, goToPartyDist[i] + returnHomeDist[i]);
        }
    }
    cout << maxTime << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //freopen("input.txt", "r", stdin); 

    input();
    solve();

    return 0;
}