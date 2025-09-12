#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Edge
{
    int to = -1;
    int weight = -1;
};

struct State
{
    int vertex;
    int dist;

    bool operator<(const State& right) const
    {
        return dist > right.dist;
    }
};

int V, E, K;

vector<Edge> edges[20'001];

inline void init()
{
    cin >> V >> E >> K;

    for (int i = 0; i < E; ++i)
    {
        int from, to, weight;
        cin >> from >> to >> weight;

        edges[from].emplace_back(Edge{ to, weight });
    }
}
constexpr int INF = 987654321;
inline void solve()
{
    int dist[20'001];
    fill_n(dist, V + 1, INF);

    priority_queue<State> pq;
    pq.push({ K, 0 });
    dist[K] = 0;
    
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        if (cur.dist > dist[cur.vertex]) continue;

        for (auto& e : edges[cur.vertex])
        {
            int nextDist = cur.dist + e.weight;

            if (dist[e.to] <= nextDist) continue;
            pq.push({ e.to, nextDist });
            dist[e.to] = nextDist;
        }
    }

    for (int i = 1; i <= V; ++i)
    {
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << '\n';
    }
}

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    
    {
        init();
        solve();
    }

    return 0;
}