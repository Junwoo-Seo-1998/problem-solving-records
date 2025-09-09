#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> adj[32'001];
int deg[32'001];
int n, m;

int main(void) {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for(int i=0; i<m; ++i)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		deg[b]++;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) 
	{
		if (deg[i] == 0) 
			q.push(i);
	}

	while (!q.empty()) 
	{
		int cur = q.front(); q.pop();
		cout << cur << ' ';
		for (int nxt : adj[cur]) 
		{
			deg[nxt]--;
			if (deg[nxt] == 0) 
				q.push(nxt);
		}
	}
}