#include <bits/stdc++.h>

using namespace std;

int main() 
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int numCoins, priceChoco; cin >> numCoins >> priceChoco;

  int moneyTotal = 100 * numCoins;

  if (moneyTotal >= priceChoco) cout << "Yes\n";
  else cout << "No\n";

  return 0;
}