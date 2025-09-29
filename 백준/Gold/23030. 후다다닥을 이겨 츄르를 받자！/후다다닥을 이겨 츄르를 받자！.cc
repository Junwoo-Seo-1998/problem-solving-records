#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int N;
int M;
struct station
{
    int line;
    int num;
};

struct state
{
    int curLine;
    int curStation;
    int curTime;

    bool operator<(const state& r) const
    {
        return curTime > r.curTime;
    }
};

//group , from
vector<station> connection[11][51];


inline void init()
{
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        int stations;
        cin >> stations;
        for(int s=1; s<stations; ++s)
        { 
            connection[i][s].push_back({i, s+1});
            connection[i][s+1].push_back({i, s});
        }
    }


    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int fromLine, from, toLine, to;
        cin >> fromLine >> from >> toLine >> to;

        connection[fromLine][from].push_back({ toLine, to });
        connection[toLine][to].push_back({ fromLine, from });
    }
}

int checkTime(int T, int _fromLine, int _from, int _toLine, int _to)
{
    int optimalTime[11][51];
    memset(optimalTime, -1, sizeof(optimalTime));


    priority_queue<state>pq;
    pq.push(state{ _fromLine, _from, 0 });
    optimalTime[_fromLine][_from] = 0;
    
    while (!pq.empty())
    {  
        auto curState = pq.top(); pq.pop();

        if (curState.curLine == _toLine && curState.curStation == _to)
            break;

        if (curState.curTime > optimalTime[curState.curLine][curState.curStation])
            continue;

        for (auto& next : connection[curState.curLine][curState.curStation])
        {
            int timeTake = next.line != curState.curLine ? T : 1;
            timeTake += curState.curTime;
            if (optimalTime[next.line][next.num]==-1 || optimalTime[next.line][next.num]>timeTake)
            {
                optimalTime[next.line][next.num] = timeTake;
                pq.push(state{ next.line, next.num, timeTake});
            }
        }
    }

    return optimalTime[_toLine][_to];
}


inline void solve()
{
    int K;
    cin >> K;

    for (int i = 0; i < K; ++i)
    {
        int T, fromLine, from, toLine, to;
        cin >> T >> fromLine >> from >> toLine >> to;

        cout << checkTime(T, fromLine, from, toLine, to) << '\n';
    }
}

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    
    {
        init();
        solve();
    }

    return 0;
}