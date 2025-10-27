#include<iostream>


int x[10'001];
int y[10'001];

using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	//freopen("input.txt", "r", stdin);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> x[i];
		cin >> y[i];
	}

	x[N] = x[0];
	y[N] = y[0];

	long long accX = 0;
	long long accY = 0;
	for (int i = 0; i < N; ++i)
	{
		accX += (long long)x[i] * (long long)y[i + 1];
		accY += (long long)y[i] * (long long)x[i + 1];
	}

	cout << fixed;
	cout.precision(1);
	cout << 0.5*abs(accX - accY);

	return 0;
}