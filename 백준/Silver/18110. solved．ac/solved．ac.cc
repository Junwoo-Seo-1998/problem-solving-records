#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int N;
	int ans = 0;
	double sum = 0;
	vector<int> list;

	cin >> N;

	if (N != 0)
	{
		for (int i = 0; i < N; i++)
		{
			int temp;
			cin >> temp;

			list.push_back(temp);
		}

		sort(list.begin(), list.end());

		int exception = round(N * 0.15);

		for (int i = exception; i < N - exception; i++)
			sum += list.at(i);

		ans = round(sum / (N - (2 * exception)));
	}
	
	cout << ans << endl;

	return 0;
}