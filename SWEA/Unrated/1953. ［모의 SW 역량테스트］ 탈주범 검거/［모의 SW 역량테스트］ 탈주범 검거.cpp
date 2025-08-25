#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct dir
{
    int x=0;
    int y=0;
};


constexpr dir Up={0, -1};
constexpr dir Down={0, 1};
constexpr dir Left={-1, 0};
constexpr dir Right={1, 0};

vector<dir> dirs[8]=
{
    {},
    {Up, Down, Left, Right},
    {Up, Down},
    {Left, Right},
    {Up, Right},
    {Down, Right},
    {Down, Left},
    {Up, Left}
};

int map[51][51];
int visit[51][51];

int N, M, R, C, L;

inline void init()
{
    cin>>N>>M>>R>>C>>L;

    for(int n=0; n<N; ++n)
    {
        for(int m=0; m<M; ++m)
        {
            cin>>map[n][m];
            visit[n][m]=-1;
        }
    }
}

inline void solve()
{
    queue<pair<int, int>> q;
    q.push({C,R});
    visit[R][C]=0;
    int count=1;

    while(!q.empty())
    {
        auto p=q.front();
        q.pop();

        int x=p.first;
        int y=p.second;

        if(visit[y][x]+1==L) continue;

        int type=map[y][x];
        for(auto& d:dirs[type])
        {
            int nx=x+d.x;
            int ny=y+d.y;
            
            if(nx<0 || ny<0 || nx>=M || ny >= N) continue;
            
            if(map[ny][nx]==0) continue;
            if(visit[ny][nx]!=-1) continue;
            
            bool isConnected=false;
            int nextType=map[ny][nx];
            for(auto& pipeDir:dirs[nextType])
            {
                if(ny+pipeDir.y==y  && nx+pipeDir.x==x)
                {
                    isConnected=true;
                    break;
                }
            }

            if(!isConnected) continue;

            visit[ny][nx]=visit[y][x]+1;
            count++;

            q.push({nx, ny});
        }
    }

    cout<<count<<endl;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        init();
        cout<<"#"<<test_case<<" ";
        solve();
	}
	return 0;
}