#include <iostream>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int t;
	cin >> t;
	
	for(int i = 1; i <= t; i++) {
		for(int k = 0; k < i; k++) {
			cout << "*";
		}
		cout << '\n';
	}
	
	return 0;
}