#include <iostream>
#define endl '\n'
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		int sum = 0;	int min = 100;
		for (int j = 0; j < 7; j++) {
			cin >> a;
			if (a % 2 == 0) {
				sum += a;
				if (a < min) { min = a; }
			}
		}
		cout << sum << " " << min << endl;
	}
}