#include<iostream>
#include <limits>
using namespace std;

int main()
{
    int T;
    cin >> T;
    int B, W, X, Y, Z;
    for (int tc = 1; tc <= T; ++tc)
    {
        cin >> B >> W >> X >> Y >> Z;
        int maxVal = numeric_limits<int>::min();
        int maxSwaps = min(B, W);

        for (int swaps = 0; swaps <= maxSwaps; swaps++)
            maxVal = max(maxVal, (B - swaps) * X + (W - swaps) * Y + 2 * swaps * Z);
        cout << maxVal << endl;
    }
    return 0;
}