#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;


/*
1. 임의로 구슬 N 떨구고 
몇번째 어떤 col 선택했는지 Path 기록 하고 dfs

2. path 기록한대로 시뮬
기저= 구슬 갯수 만큼
그대로 시뮬
원본 배열 복사해서 확인하고 정답 후보 구하기.
a. 터트리는 과정=플러드 필
b. 중력 적용 

1.입력
2.재귀 path[] 작성
3.기저에서 path[] 시뮬
	a. 플러드필
	b. 중력 구현	
*/
int ans;
int N;
int H, W;
int Map[20][20];
int Copy[20][20];
int visited[20][20];
int total;//남은 블럭수
int totalCopy; //블럭의 총개수 시뮬용
int path[5]; // index: 몇번째 구슬 val: 선택한 col 번호

int dirY[] = { -1, 1, 0, 0 };
int dirX[] = { 0, 0, -1, 1 };

struct Node
{
	int y = 0;
	int x = 0;
};
void init() 
{
	ans = 21e8;
	total = 0;
	memset(Map, 0, sizeof(Map));
}

void input()
{
	cin >> N >> W >> H;

	for (int y = 0; y < H; ++y)
	{
		for (int x = 0; x < W; ++x)
		{
			cin >> Map[y][x];
			if (Map[y][x] != 0)
				total += 1; //블럭의 총개수를 미리 카운팅
				
		}
	}
}

void pang(int col)
{
	//1. 사전 준비
	memset(visited, 0, sizeof(visited));

	queue<Node> q; 
	//2. 시작노드 큐에 등록
	//해당 col 에서 가장 높은 위치 좌표부터 queue에 등록

	for (int y = 0; y < H; ++y)
	{
		//젤 위 떨군거만 체크하면 어차피 밑에 다터지니까 위에만 체크
		if (Copy[y][col] != 0)
		{
			visited[y][col] = 1;
			q.push({ y, col });
			break;
		}
	}

	//3-5
	while (!q.empty())
	{
		//3. 맨 앞 노드 확인 추출
		Node now = q.front(); q.pop();

		//하나의 블럭 사라짐
		totalCopy -= 1;

		//4. next 찾기 등록
		int dist = Copy[now.y][now.x]; //범위 확인
		Copy[now.y][now.x] = 0;

		for (int d = 1; d < dist; ++d)
		{
			for (int i = 0; i < 4; ++i)
			{
				int ny = now.y + dirY[i]*d;
				int nx = now.x + dirX[i]*d;


				//경계
				if (ny >= H || nx >= W || nx < 0 || ny < 0) continue;
				//블럭 아닌 경우 예외
				if (Copy[ny][nx] == 0) continue;
				//이미 터트림
				if (visited[ny][nx] == 1) continue;

				visited[ny][nx] = 1;
				q.push({ ny, nx });
			}

		}
	}


}

void pullDown()
{
	for (int col = 0; col < W; ++col)
	{
		int writeCur = H - 1;
		for (int readCur = H - 1; readCur >= 0; readCur--)
		{
			if (Copy[readCur][col] != 0)
			{
				Copy[writeCur][col] = Copy[readCur][col];
				writeCur--;
			}
		}

		while (writeCur >= 0)
		{
			Copy[writeCur][col] = 0;
			writeCur--;
		}
	}
}

void dfs(int cnt)
{
	//일단 경로를 만든다
	//1. 기저
	if (ans == 0) return; //<- 이거 핵심 없으면 느림 더이상 최적인 해를 구할 수 없으니까 이게 베이스 케이스

	if (cnt >= N)
	{
		//만들어진 경로대로 시뮬
		//원본 복사 필요, 초기화 신경쓰기
		memcpy(Copy, Map, sizeof(Map));
		totalCopy = total;
			
		//N개의 구슬을 path에 기록된 대로 처리
		for (int i = 0; i < N; ++i)
		{
			//이전
			pang(path[i]); //Flood Fill

			//이후
			pullDown();//중력 구현
		}

		ans = min(ans, totalCopy);
		return;
	}


	//2. 재귀
	//now> now+1 선택할 수 있는 경우의 수
	// 0~W-1 까지 해당 col 중 하나 선택 진행

	for (int i = 0; i < W; ++i)
	{
		path[cnt] = i;
		dfs(cnt + 1);
		path[cnt] = 0;
	}
}

void solve(int test)
{
	dfs(0); //구슬 N개를 다양한 col 위치에서 떨궈서 만들 수 있는 최소 값
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