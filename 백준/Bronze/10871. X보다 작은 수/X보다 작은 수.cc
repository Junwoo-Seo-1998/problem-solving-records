#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    cin >> n >> x;

    for (int i = 0; i < n; ++i)
    {
        int number;
        cin >> number;

        if (number < x)
        {
            cout << number << " ";
        }
    }

    cout << "\n"; 
    return 0;
}