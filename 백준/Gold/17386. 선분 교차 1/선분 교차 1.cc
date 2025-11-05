#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

struct vec
{
    long long x=0;
    long long y=0;
    long long z=0;
    vec operator-(const vec& r) const
    {
        return { x - r.x, y - r.y, z - r.z };
    }
};

struct line
{
    vec p1;
    vec p2;
};

vec cross(const vec& v1, const vec& v2)
{
    vec ret;

    ret.x = v1.y * v2.z - v1.z * v2.y;
    ret.y = -(v1.x * v2.z - v1.z * v2.x);
    ret.z = v1.x * v2.y - v2.x * v1.y;

    return ret;
}

int test(const line& l1, const line& l2)
{
    vec dir = l1.p2 - l1.p1;

    vec dirP1 = l2.p1 - l1.p1;
    vec dirP2 = l2.p2 - l1.p1;

    vec crossVec1 = cross(dir, dirP1);
    vec crossVec2 = cross(dir, dirP2);

    //return crossVec1.z * crossVec2.z;

    if ((crossVec1.z > 0 && crossVec2.z < 0) || (crossVec1.z < 0 && crossVec2.z > 0))
    {
        return -1;
    }
    
    return 1;
}

bool lineTest(const line& l1, const line& l2)
{
    long long t1 = test(l1, l2);
    long long t2 = test(l2, l1);

    if (t1 < 0 && t2 < 0)
    {
        return true;
    }

    return false;
}



void solve()
{
    vec p1, p2;
    vec p3, p4;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;

    cin >> p3.x >> p3.y >> p4.x >> p4.y;

    line l1 = { p1, p2 };
    line l2 = { p3, p4 };

    cout << (int)lineTest(l1, l2) << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //freopen("input.txt", "r", stdin); 

    solve();

    return 0;
}