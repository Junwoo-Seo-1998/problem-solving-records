#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
struct vec
{
    int x = 0;
    int y = 0;
    long long distSq() const
    {
        return (long long)x * x + (long long)y * y;
    }
};

struct point
{
    int x = 0;
    int y = 0;

    vec operator-(const point& p) const
    {
        return { x - p.x, y - p.y };
    }

    bool operator<(const point& p) const
    {
        if (x == p.x)
            return y < p.y;
        return x < p.x;
    }
};

int N;
vector<point> points;

inline long long crossZ(const vec& v1, const vec& v2)
{
    return ((long long)v1.x) * v2.y - ((long long)v1.y) * v2.x;
}

//in-t out-f
inline bool ccw(const vec& v1, const vec& v2)
{
    return crossZ(v1, v2) > 0;
}

inline bool ccw(const point& p0, const point& p1, const point& p2)
{
    return crossZ(p1 - p0, p2 - p0) > 0;
}


void input()
{
    cin >> N;
    points.reserve(N);

    for (int i = 0; i < N; ++i)
    {
        int x, y;
        cin >> x >> y;
        points.emplace_back(point{ x, y });
    }

    {
        auto minElem = min_element(points.begin(), points.end());
        swap(*minElem, points.front());
    }

    sort(points.begin() + 1, points.end(), [&](const point& p1, const point& p2) {
        auto v1 = p1 - points[0];
        auto v2 = p2 - points[0];

        long long z = crossZ(v1, v2);

        if (z == 0)
        {
            return v1.distSq() < v2.distSq();
        }

        return z > 0;
        });
}

void solve()
{
    vector<int> ans;
    ans.reserve(N);

    ans.emplace_back(0);
    ans.emplace_back(1);

    for (int i = 2; i < N; ++i)
    {
        auto& cur = points[i];

        while ((ans.size() > 1))
        {
            if (ccw(points[*(ans.rbegin()+1)], points[*ans.rbegin()], cur))
            {
                break;
            }
            ans.pop_back();
        }
        ans.emplace_back(i);
    }

    cout << ans.size();
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