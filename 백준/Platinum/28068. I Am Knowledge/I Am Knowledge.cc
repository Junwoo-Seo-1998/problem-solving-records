#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

vector<pair<int, int>> gain;
vector<pair<int, int>> loss;
int N;

void input()
{
    cin >> N;

    gain.reserve(N);
    loss.reserve(N);

    for (int i = 0; i < N; ++i)
    {
        int a, b;
        cin >> a >> b;
        if (a<b)
        {
            gain.emplace_back(a, b);
        }
        else
        {
            loss.emplace_back(a, b);
        }
    }
}

void solve()
{
    sort(gain.begin(), gain.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
    });

    sort(loss.begin(), loss.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    long long happy = 0;
    for (auto& p : gain)
    {
        if (p.first > happy)
        {
            cout << 0;
            return;
        }

        happy -= p.first;
        happy += p.second;
    }

    for (auto& p : loss)
    {
        if (p.first > happy)
        {
            cout << 0;
            return;
        }

        happy -= p.first;
        happy += p.second;
    }

    cout << 1;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //freopen("input.txt", "r", stdin); 

    input();

    solve();

    return 0;
}