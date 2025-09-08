#include<iostream>
#include<algorithm>
using namespace std;
/*
입력이 크루스칼하기 좋게 되어있는거 같음
실수 
루프에 e를 인덱스로 쓰면, 무한 루프 빠질수도 있음.
*/

int V, E;

struct Edge
{
    int from = -1;
    int to = -1;
    int weight = -1;

    bool operator<(const Edge& e) const
    {
        return weight < e.weight;
    }
};

int parent[10001];
Edge edges[100000];

int findParent(int target)
{
    if (parent[target] == target)
        return target;

    return parent[target] = findParent(parent[target]);
}

void merge(int pa, int pb)
{
    if (pa == pb) return;

    if (pa < pb)
    {
        parent[pb] = pa;
        return;
    }

    //pa>pb
    
    parent[pa] = pb;
}


void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void input()
{
    cin >> V >> E;
    
    for (int i = 0; i <= V; ++i)
    {
        parent[i] = i;
    }


    for (int i = 0; i < E; ++i)
    {
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;
    }

    sort(edges, edges + E);
}

void solve()
{
    long long ans = 0;

    int e = 0;
    for(int i=0; i<E; ++i)
    {
        if (e == V - 1) break;

        int a = findParent(edges[i].from);
        int b = findParent(edges[i].to);

        if (a == b) continue;

        merge(a, b);
        ans += edges[i].weight;
        e++;
    }

    cout << ans << '\n';
}


int main()
{
    init();
    //freopen("input.txt", "r", stdin);
    input();
    solve();

    return 0;
}