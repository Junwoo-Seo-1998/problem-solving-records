#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

/*
1. 입력
2. 특정 좌표 임의적으로 클릭
결국 bfs
큐에 등록과정
	1. 지뢰가 아닌곳
	- MAP[][] == ‘.’
	2. 아직 확인하지 않은곳
	3. 8방향의 칸도 자동으로 숫자를 표시해준다.
	특정 좌표 기준 주변 8방향에 지뢰가 없어야 한다. check_zero()
3. 남아 있는 개수를 카운팅
	1. 지뢰가 아닌 곳
	-MAP[][]==’.’
	2. 확인하지 않은 곳
	-visited[][]==0
*/


char MAP[301][301];
int visited[301][301];
int N;
int ans;

int dirY[] = { 1,-1,0,0, 1,1,-1,-1 };
int dirX[] = { 0,0,1,-1, 1,-1, 1, -1 };



struct Node
{
	int y=0;
	int x=0;
};

queue<Node> q;

void init() {
	ans = 0;
	memset(visited, 0, sizeof(visited));
	memset(MAP, 0, sizeof(MAP));
}

void input()
{
	cin >> N;
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
			cin >> MAP[y][x];
	}
}

//주변 8방
bool checkZero(int y, int x)
{
	for (int i = 0; i < 8; ++i)
	{
		int ny = y + dirY[i];
		int nx = x + dirX[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

		if (MAP[ny][nx] == '*')
			return false;
	}

	return true;
}

void check()
{
	//남아있는 개수 세기

	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			if (MAP[y][x] == '.' && visited[y][x] == 0)
				ans += 1;
		}
	}
}

void solve(int test)
{
	//1.사전 준비
	//모든 좌표에서 검증
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			//2. 시작 노드 큐에 등록
			//a. 방문 되어있지 않은곳.
			//b. MAP[][]=='.' 지뢰가 아닌곳
			//c. 주변 8방향에 지뢰가 없어야한다.
			if (visited[y][x] == 0 && MAP[y][x] == '.' && checkZero(y, x))
			{
				ans += 1;
				visited[y][x] = 1;
				q.push({ y,x });
			}

			//3-5 반복
			while (!q.empty())
			{
				//3. 맨앞노드 확인 및 추출
				Node now = q.front(); q.pop();
				//4. next 찾기 및 등록

				for (int i = 0; i < 8; ++i)
				{
					int ny = now.y + dirY[i];
					int nx = now.x + dirX[i];

					//a. 경계체크
					if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
					//b. 방문 여부 체크
					if (visited[ny][nx] == 1) continue;
					//c. 맵에서 지뢰가 아니여야함.
					if (MAP[ny][nx] == '*') continue;

					visited[ny][nx] = 1;

					//등록 해줄 때, 주변 8 방향에 지뢰 없어야 push
					if (checkZero(ny, nx))
						q.push({ ny, nx });
				}
			}

		}
	}

	
	check();
	cout<<'#'<<test<<' '<<ans<<'\n';
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		init();
		input();
		solve(t);
	}
}