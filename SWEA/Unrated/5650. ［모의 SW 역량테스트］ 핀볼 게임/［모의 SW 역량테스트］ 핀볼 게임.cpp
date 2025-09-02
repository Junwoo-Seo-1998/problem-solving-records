#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;


/*
1. 입력
2. 시뮬
	시작위치로 돌아옴
	a. 벽인경우
	b. 블랙홀에 빠짐
	c. 웜홀에 빠짐
	d. 블럭에 부딪힘
3.정답
모든 좌표에서 모든 방향으로, 최대값
시작은 맵에서 0일때
*/

int N;
int ans;
int Map[101][101];
int dirY[] = { -1, 1, 0, 0 };
int dirX[] = { 0, 0, -1, 1 };

struct Node
{
	int y;
	int x;
};

int blockdir[][4] = {
	{},//더미
	//상 0 하 1 좌 2 우 3


	{1, 3, 0, 2}, //하 우 상 좌
	{3, 0, 1, 2}, //우 상 하 좌 
	{2, 0, 3, 1}, //좌 상 우 하
	{1, 2, 3, 0}, //하 좌 우 상
	{1, 0, 3, 2}, //하 상 우 좌
};


vector<Node> wormhole[11]; //웜홀 좌표관리

void init() 
{
	N = -1;
	ans = -1;

	for (int i = 0; i < 11; ++i)
		wormhole[i].clear();
}

void input()
{
	cin >> N;

	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			cin >> Map[y][x];
			if(Map[y][x]>=6)
				wormhole[Map[y][x]].push_back({ y, x });
		}
	}
}
int simulate(int y, int x, int dir)
{
	int ny = y;
	int nx = x;
	int nd = dir;
	int flag = 0; //출발 여부
	int cnt = 0;

	while (true)
	{
		if (ny == y && nx == x && flag == 1)
			break; //시작으로 돌아옴

		//시작위치로 돌아옴
		//일단 움직이자
		ny = ny + dirY[nd];
		nx = nx + dirX[nd];
		flag = 1;// 출발 완료

		//a.벽인경우
		if (ny < 0 || nx < 0 || ny >= N || nx >= N)
		{
			ny = ny - dirY[nd];
			nx = nx - dirX[nd];

			//상0 하1 좌2 우3
			if (nd % 2 == 0)
				nd += 1;
			else
				nd -= 1;
			cnt += 1;//카운팅
		}

		//b.블랙홀에 빠짐
		if (Map[ny][nx] == -1) break;

		//c.웜홀에 빠짐
		if (Map[ny][nx] >= 6)
		{
			//1.웜홀 번호 확인
			int wormholeNum = Map[ny][nx];
			//2.목록에서 확인후 가져오기
			Node nextWormHole =
				(wormhole[wormholeNum][0].x == nx && wormhole[wormholeNum][0].y == ny)
				? wormhole[wormholeNum][1] : wormhole[wormholeNum][0];

			ny = nextWormHole.y;
			nx = nextWormHole.x;

			continue;
		}

		//d.블럭에 부딪힘
		if (Map[ny][nx] >= 1 && Map[ny][nx] <= 5)
		{
			nd = blockdir[Map[ny][nx]][nd];
			//ny += dirY[nd]; 좌우에 끼면 터짐
			//nx += dirX[nd];
			cnt += 1;
		}
	}
	return cnt;
}

void solve(int test)
{
	// 모든 방향 시뮬
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			if (Map[y][x] != 0) continue;

			for (int d = 0; d < 4; ++d)
			{
				int temp = simulate(y, x, d);
				if (temp > ans) ans = temp;
			}
		}
	}

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