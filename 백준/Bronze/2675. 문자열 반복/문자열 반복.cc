#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int t, R;
	string s;

	cin >> t;

	while (t--) {
		cin >> R >> s;

		for (int i = 0; i < s.length(); i++) {
			for (int k = 0; k < R; k++) {
				cout << s[i];
			}
		}
		cout << '\n';
	}



	return 0;
}