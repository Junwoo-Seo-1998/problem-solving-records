#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
int N;
int cafe[20][20];

unordered_set<int> eaten;

int maxLen;

inline bool isIn(int y, int x)
{
    if (y < 0 || x < 0 || y >= N || x >= N)
        return false;
    return true;
}

void check(int A, int B, int y, int x)
{
    if (!isIn(y + B, x - B) || !isIn(y + A, x + A) || !isIn(y + A + B, x + A - B))
        return;

    pair<int, int> dir = {1, -1};
    eaten.clear();

    for(int i=0; i<2; ++i)
    {
        dir = {-dir.second , dir.first};
        for (int a = 1; a <= A; ++a)
        {
            if (eaten.find(cafe[y][x]) != eaten.end())
                return;

            eaten.insert(cafe[y][x]);
            x += dir.first;
            y += dir.second;
        }

        dir = {-dir.second , dir.first};
        for (int b = 1; b <= B; ++b)
        {
            if (eaten.find(cafe[y][x]) != eaten.end())
                return;

            eaten.insert(cafe[y][x]);
            x += dir.first;
            y += dir.second;
        }
    }

    maxLen=max((int)eaten.size(), maxLen);
}

inline int solve()
{
    cin >> N;

    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            cin >> cafe[y][x];
        }
    }
    maxLen = 0;
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            for(int a=1; a<N; ++a)
            {
                for(int b=1; b<N; ++b)
                {
                    check(a, b, y, x);
                }
            }
        }
    }

    return (maxLen == 0) ? -1 : maxLen;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        cout << "#" << t << " " << solve() << "\n";
    }

    return 0;
}