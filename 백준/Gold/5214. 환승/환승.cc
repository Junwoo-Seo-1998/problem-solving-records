#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K, M;

vector<int> adj[100'000 + 1 + 1000 + 1];
int visit[100'000 + 1 +  1000 + 1];

void bfs() {
	queue<int> q;

	q.push(1);
	visit[1] = 1;

	while (!q.empty()) 
    {
		int cur = q.front();
		q.pop();

		if (cur == N)
			return;

		for (int i = 0; i < adj[cur].size(); i++) 
        {
			int next = adj[cur][i];

			if (visit[next] <= 0) 
            {
				if (next > N)
					visit[next] = visit[cur];
				else
					visit[next] = visit[cur] + 1;

				q.push(next);
			}
		}
	}
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
	int i, j, temp;

	cin >> N >> K >> M;

	visit[N] = -1;
	for (i = 1; i <= M; i++) {
		for (j = 0; j < K; j++) {
			cin >> temp;
			adj[N+i].push_back(temp);
			adj[temp].push_back(N + i);
		}
	}

	bfs();
	cout << visit[N] << "\n";

	return 0;
}