#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

struct MAP
{
	int maxColonyNum; // 해당 셀을 차지하고 있는 군집 번호
	int maxColonyCnt; // 해당 셀 군집 중 미생물이 가장 많았던 군집의 미생물 수 (비교용)
	int totalCnt;     // 해당 셀에 모인 미생물 총합
	int finalDir;     // 해당 셀을 차지한 군집의 최종 방향
};

struct Colony
{
	int row, col;
	int cnt;
	int dir;
};

vector<Colony> colony;
vector<int> alive;
int N, M, K;

void init()
{
	alive.clear();
	colony.clear();
	N = M = K = 0;
}

void input()
{
	cin >> N >> M >> K;
	colony.push_back({ 0,0,0,0 }); // 더미 데이터
	for (int i = 1; i <= K; ++i)
	{
		int y, x, cnt, dir;
		cin >> y >> x >> cnt >> dir;
		colony.push_back({ y,x,cnt,dir });
		alive.push_back(i);
	}
}

void simulation()
{
	for (int time = 0; time < M; ++time)
	{
		// 1단계: 모든 군집의 이동 후 상태를 임시 'next_colony' 벡터에 저장
		vector<Colony> next_colony = colony; // 현재 상태 복사
		for (int i = 0; i < alive.size(); ++i)
		{
			int nowColonyNum = alive[i];

			int ydir[] = { 0,-1,1,0,0 };
			int xdir[] = { 0,0,0,-1,1 };

			// 복사본인 next_colony를 이동시켜서 결과를 미리 계산
			next_colony[nowColonyNum].row += ydir[colony[nowColonyNum].dir];
			next_colony[nowColonyNum].col += xdir[colony[nowColonyNum].dir];

			// 경계선 닿는 경우
			int r = next_colony[nowColonyNum].row;
			int c = next_colony[nowColonyNum].col;
			if (r <= 0 || r >= N - 1 || c <= 0 || c >= N - 1)
			{
				next_colony[nowColonyNum].cnt /= 2;
				if (next_colony[nowColonyNum].dir % 2 == 1) next_colony[nowColonyNum].dir += 1;
				else next_colony[nowColonyNum].dir -= 1;
			}
		}

		// 2단계: 임시 'next_colony'를 기준으로 병합하고 원본 업데이트
		MAP Map[100][100] = { 0, }; // N의 최대 크기는 100

		for (int i = 0; i < alive.size(); ++i)
		{
			int nowColonyNum = alive[i];
			Colony movedColony = next_colony[nowColonyNum];

			if (movedColony.cnt == 0) continue;

			int r = movedColony.row;
			int c = movedColony.col;

			// 이 셀에 모이는 미생물 총합을 더함
			Map[r][c].totalCnt += movedColony.cnt;

			// 이 셀에 도착한 군집 중, 현재 군집의 미생물 수가 가장 많으면
			if (movedColony.cnt > Map[r][c].maxColonyCnt)
			{
				Map[r][c].maxColonyCnt = movedColony.cnt; // 최대 미생물 수 갱신
				Map[r][c].maxColonyNum = nowColonyNum;    // 이 셀의 주인은 nowColonyNum
				Map[r][c].finalDir = movedColony.dir;     // 최종 방향도 갱신
			}
		}

		// 3단계: Map의 최종 결과를 바탕으로 원본 colony와 alive 리스트를 정리
		vector<int> newAlive;
		for (int r = 0; r < N; ++r)
		{
			for (int c = 0; c < N; ++c)
			{
				if (Map[r][c].totalCnt > 0)
				{
					int winnerNum = Map[r][c].maxColonyNum;
					newAlive.push_back(winnerNum);

					// 원본 colony 데이터를 최종 결과로 덮어쓰기
					colony[winnerNum].row = r;
					colony[winnerNum].col = c;
					colony[winnerNum].cnt = Map[r][c].totalCnt;
					colony[winnerNum].dir = Map[r][c].finalDir;
				}
			}
		}
		alive = newAlive;
	}
}

void solve(int test)
{
	simulation();
	int sum = 0;
	for (int i = 0; i < alive.size(); ++i)
	{
		sum += colony[alive[i]].cnt;
	}
	cout << "#" << test << " " << sum << '\n';
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc)
	{
		init();
		input();
		solve(tc);
	}
	return 0;
}