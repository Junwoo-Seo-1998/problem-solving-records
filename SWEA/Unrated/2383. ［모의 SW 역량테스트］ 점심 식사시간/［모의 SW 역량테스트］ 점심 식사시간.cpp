#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

int N; //한변 길이
int MAP[15][15];
int ans;

struct Coord
{
    int x;
    int y;
};

int calcDist(const Coord& a, const Coord& b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

struct Element
{
    Coord person;
    Coord stair;
    bool operator<(const Element& right) const {
        int lDist = calcDist(person, stair);
        int rDist = calcDist(right.person, right.stair);

        if (lDist < rDist) return false;
        if (lDist > rDist) return true;

        return false;
    }
};

vector<Coord> persons;
vector<Coord> stairs;

vector<int>path; //각사람이 어떤 계단 선택

void init()
{
    ans = 21e8;
    persons.clear();
    stairs.clear();
    memset(MAP, 0, sizeof(MAP));
}

void input()
{
    cin >> N;
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            cin >> MAP[y][x];
            if (MAP[y][x] == 1)
            {
                persons.push_back({ x,y });
            }
            else if (MAP[y][x] >= 2)
            {
                stairs.push_back({ x,y });
            }

        }
    }
}

int simulation()
{
    priority_queue<Element> pq[2];//계단별로 필요

    for (int i = 0; i < path.size(); ++i)
    {
        //i:사람 
        //ii:path[i] 선택한 계단 번호 
        pq[path[i]].push({ persons[i], stairs[path[i]] });
    }

    //계단별로 소요시간 계산
    int timeTook = -1;



    for (int stairNum = 0; stairNum < 2; ++stairNum)
    {
        queue<int>useList;
        while (!pq[stairNum].empty())
        {
            Element now = pq[stairNum].top();
            pq[stairNum].pop();

            //사람이 계단으로 이동 완료
            //도착시간
            int arriveTime = calcDist(now.person, now.stair) + 1;

            //계단 사용시간
            int stairTime = MAP[now.stair.y][now.stair.x];

            //케이스 3개
            //사람이 3명미만
            //계단위
            //    앞사람이 있는 경우, 없는경우

            if (useList.size() < 3)
            {
                useList.push(arriveTime + stairTime);
                timeTook = max(arriveTime + stairTime, timeTook);
            }
            else
            {
                int prevTime = useList.front(); useList.pop();

                //앞 사람이 이미 있어서 기다려야됨
                if (prevTime > arriveTime) {
                    useList.push(prevTime + stairTime);
                    timeTook = max(prevTime + stairTime, timeTook);
                }
                //도착과 자리가 난 경우
                else
                {
                    int finishTime = arriveTime + stairTime;
                    useList.push(finishTime);
                    timeTook = max(finishTime, timeTook);
                }
                
            }
        }
    }

    return timeTook;
}


void dfs(int now)
{
    //기저
    if (now >= persons.size()) { //모든사람들이 계단 선택
        //선택이 끝났다면 시뮬레이션
        ans = min(ans, simulation());
        return;
    }

    //재귀
    for (int i = 0; i < 2; ++i)
    {
        path.push_back(i);
        dfs(now + 1);
        path.pop_back();
    }
}

void solve(int test)
{
    dfs(0);
    cout << '#' << test << ' ' << ans << '\n';
}

int main(int argc, char** argv)
{
    int test_case;
    int T;

    //freopen("input.txt", "r", stdin);
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        init();
        input();
        solve(test_case);
    }
    return 0;
}