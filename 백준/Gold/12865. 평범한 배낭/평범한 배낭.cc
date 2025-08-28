#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
#include<array>
#include<deque>
#include<string>
#include<set>
#include<limits>
using namespace std;
int N, K;

int v[101];
int w[101];

/*
int func(int weight, int current)
{
	if (current == N) return 0;
	if (weight == 0) return 0;

	int maxValue = -1;
	if (weight - w[current] >= 0)
	{
		maxValue=max(func(weight - w[current], current + 1)+v[current], maxValue);
	}
	
	maxValue=max(func(weight, current + 1), maxValue);

	return maxValue;
}
*/

vector<vector<int>> dp;
int func(int weight, int current)
{
	if (dp[weight][current] != -1)
		return dp[weight][current];

	if (current == N) return dp[weight][current]=0;
	if (weight == 0) return dp[weight][current]=0;

	int maxValue = -1;
	if (weight - w[current] >= 0)
	{
		maxValue = max(func(weight - w[current], current + 1) + v[current], maxValue);
	}

	maxValue = max(func(weight, current + 1), maxValue);

	return dp[weight][current] = maxValue;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
	
	cin >> N >> K;
	
	for (int i = 0; i < N; ++i)
	{
		cin >> w[i];
		cin >> v[i];
	}
	dp.assign(K + 1, vector<int>(N + 1, -1));
	cout<<func(K, 0);

	return 0;
}