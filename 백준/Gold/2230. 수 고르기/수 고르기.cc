#include<iostream>
#include<cstring>
#include<array>
#include<algorithm>
#include<limits>
using namespace std;
array<long long, 100'010> arr;
long N;
long M;

inline void init()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.begin() + N);
}
inline void solve()
{
	long long ans = numeric_limits<int>::max();
	for (int i = 0; i < N; ++i)
	{
		auto found = lower_bound(arr.begin() + i, arr.begin() + N, arr[i]+M);
		if(found != arr.begin() + N)
			ans = min(ans, *found-arr[i]);
		
	}
	cout << ans << '\n';
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);

	/*
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t)
	*/
	{
		init();
		solve();
	}
	return 0;
}