#include<iostream>
#include<algorithm>

using namespace std;

int N;
pair<int, int> times[100'001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	//freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> times[i].second >> times[i].first;
	}

	sort(times, times + N);

	int count = 1;
	int last = times[0].first;

	for (int i = 1; i < N; ++i)
	{
		if (last <= times[i].second)
		{
			last = times[i].first;
			++count;
		}
	}

	cout << count << '\n';

	return 0;
}