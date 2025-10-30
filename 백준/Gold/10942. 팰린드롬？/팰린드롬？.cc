#include<iostream>
#include<array>
#include<cstring>
using namespace std;

int N;
array<int, 2001> arr;

int dp[2001][2001];


bool recv(int s, int e)
{
	if (dp[s][e] != -1)
	{
		return dp[s][e];
	}

	if (s >= e)
	{
		return dp[s][e] = true;
	}

	if (arr[s] != arr[e])
		return dp[s][e] = false;

	return dp[s][e] = recv(s + 1, e - 1);
}


void solve()
{
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}
	//precompute

	//
	int M;
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int s, e;
		cin >> s >> e;
		cout << recv(s - 1, e - 1)<<'\n';
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	//freopen("input.txt", "r", stdin);

	solve();

	return 0;
}