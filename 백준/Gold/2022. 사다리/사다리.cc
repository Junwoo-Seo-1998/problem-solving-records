#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

double x, y, c;
double check(double d) {
	double sqrt1 = sqrt(x*x - d * d);
	double sqrt2 = sqrt(y*y - d * d);
	return sqrt1 * sqrt2 / (sqrt1 + sqrt2);
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);

	cin >> x >> y >> c;

	double left = 0;
	double right = min(x, y);
	while (right - left > 1e-6) 
	{
		double mid = (left + right) / 2.0;
		if (check(mid) > c)
			left = mid;
		else
			right = mid;
	}
	cout<<("%.3f\n", left);

	return 0;
}