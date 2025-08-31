#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>
#include <string>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <chrono>
#include <cstring>
using namespace std;

void setup_io()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
}

struct Node {
    int x;
    int y;
    int dir;
    int energy;
    int isAlive;
};

int N;//원자 개수
int ydir[] = { 1, -1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };

vector<Node> v; //원자들의 정보리스트

int map[4001][4001]; // 해당위치에 있는 원자들의 개수
int cnt; //살아있는 원자들의 개수

void init()
{
    memset(map, 0, sizeof(map));
    N = 0;
    cnt = 0;
    v.clear();
}

void input()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int x, y, dir, energy;
        cin >> x >> y >> dir >> energy;

        //좌표 맵핑
        x = (x + 1000) * 2;
        y = (y + 1000) * 2;

        v.push_back({ x, y, dir, energy, 1 });

        ++cnt;

        //map[x][y]=1 의미는 해당위치에 원자 1개가 살아있다

        map[x][y] = 1;
    }
}

int simulate()
{
    int energy = 0;
    //원자들이 살아있는 동안
    while (cnt > 0)
    {//모든 원소 이동
        for (int i = 0; i < v.size(); ++i)
        {
            Node& now = v[i];//하나씩 확인

            if (!now.isAlive) continue;

            //다음 위치 확인
            int nx = now.x + xdir[now.dir];
            int ny = now.y + ydir[now.dir];

            //경계 처리
            if (ny >= 4000 || nx >= 4000 || ny < 0 || nx < 0)
            {// 애초에 목록에서 제외
                v[i].isAlive = 0;
                map[now.x][now.y] = 0; //해당위치에는 원자가 없다
                cnt -= 1; // 하나 소멸
                continue;
            }

            // 범위 내에 살아있다
            map[nx][ny] += 1;
            //이전 좌표 정보 업데이트
            map[now.x][now.y] = 0;

            //실제 원자 목록 업데이트
            v[i].x = nx;
            v[i].y = ny;

        }
        //움직이고 나서 확인
        // 충돌 처리 2개 이상이라면
        //ans+=확인하는 원자의 에너지 모두 소멸
        for (int i = 0; i < v.size(); ++i)
        {
            Node& now = v[i];
            if (!now.isAlive) continue;

            //2개 이상의 원자가 모두 충돌한다면
            if (map[now.x][now.y] >= 2)
            {
                for (int j = 0; j < v.size(); ++j)
                {
                    // 만약 isAlive 가 아니면 제외
                    if (!v[j].isAlive) continue;

                    if (v[j].x == now.x && v[j].y == now.y)
                    {
                        //에너지 방출 총합
                        energy += v[j].energy;
                        v[j].isAlive = 0;
                        cnt--;
                    }
                }
                //해당 좌표에는 아무것도 없다
                map[now.x][now.y] = 0;
            }
        }
    }

    return energy;
}

void solve(int t)
{
    int ans = -1;

    ans = simulate();
    cout << "#" << t << " " << ans << '\n';
}

int main(void)
{

    setup_io();

    //freopen("input.txt", "r", stdin);

    int test = 0;
    cin >> test;
    for (int t = 1; t <= test; ++t)
    {
        //cout << "#" << t + 1 << " ";
        init();
        input();
        solve(t);
    }

    return 0;
}