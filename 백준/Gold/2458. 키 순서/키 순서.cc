#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int N, M;

vector<vector<int>> map;
vector<vector<int>> reversedMap;

void init() 
{
	N = M = -1;
}

void input()
{
	cin >> N >> M;

	map.assign(N+1, vector<int>());
	reversedMap.assign(N+1, vector<int>());
	for (int i = 0; i < M; ++i)
	{
		int from, to;
		cin >> from >> to;
		map[from].push_back(to);
		reversedMap[to].push_back(from);
	}
}

int howMany(int start, bool beforeOrAfter)
{
	queue<int> bfs;
	bool visited[501] = { 0, };
	bfs.push(start);
	visited[start] = true;

	auto& mapToCheck = (beforeOrAfter) ? map : reversedMap;

	int cnt = 0;

	while (!bfs.empty())
	{
		int from = bfs.front();
		bfs.pop();

		for (int to: mapToCheck[from])
		{
			if (visited[to]) continue;
			visited[to] = true;
			bfs.push(to);
			++cnt;
		}
	}

	return cnt;
}

void solve()
{
	int ans = 0;
	for (int i = 1; i <= N; ++i)
	{
		//count how many pep
		int before = howMany(i, true);
		int after = howMany(i, false);

		if (before + after + 1 == N)
			++ans;
	}

	cout << ans;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	init();
	input();
	solve();

	return 0;
}