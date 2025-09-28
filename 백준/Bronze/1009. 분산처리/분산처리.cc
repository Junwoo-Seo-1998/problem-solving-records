#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c = 1;
    cin >> a >> b;
    for (int i = 0; i < b; i++)
      c = (c * a) % 10;
    if (c != 0)
      cout << c << '\n';
    else
      cout << 10 << '\n';
  }
  return 0;
}