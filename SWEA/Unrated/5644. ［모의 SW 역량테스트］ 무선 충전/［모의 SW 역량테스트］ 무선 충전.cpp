#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
#include<array>
using namespace std;
int M; //이동 시간(M)
int A;//BC의 개수(A)
int alist[101];//A의 이동정보
int blist[101];//B의 이동정보

int ans;

struct BC
{
	int y;
	int x;
	int c;
	int p;
	//좌표 충전범위 처리량
};

vector<BC>bclist;// 배터리셀 리스트

int ydir[] = { 0,-1,0,1,0 };
int xdir[] = { 0,0,1,0,-1 };

void init()
{
	ans = 0;
	bclist.clear();
}

void input()
{
	cin >> M >> A;
	for (int i = 0; i < M; ++i) cin >> alist[i];
	for (int i = 0; i < M; ++i) cin >> blist[i];

	for (int i = 0; i < A; ++i)
	{
		int y, x, c, p;
		cin >> x >> y >> c >> p;
		bclist.push_back({ y, x, c, p });
	}
}

//사용자가 충전 범위 내에 있다면, 충전량P return
int check(int bcnum, int y, int x)
{
	//배터리셀의 정보 확인
	int bcy = bclist[bcnum].y;
	int bcx = bclist[bcnum].x;
	int c = bclist[bcnum].c;
	int p = bclist[bcnum].p;

	//배터리셀의 커버리지 안에 드는지 확인
	int dist = abs(bcy - y) + abs(bcx - x);

	//dist 가 커버리지 안에 든다면
	if (dist <= c) return p;

	return 0;
}


// 캐릭터의 좌표를 기준으로, 해당 좌표 최대 충전량을 돌려주는 함수
int calc(int ay, int ax, int by, int bx)
{
	int maxCharge = -1;
	for (int a_cnt = 0; a_cnt < A; ++a_cnt)
	{
		for (int b_cnt = 0; b_cnt < A; ++b_cnt)
		{
			int sumCharge = 0;
			int aCharge = check(a_cnt, ay, ax); //배터리셀, ay, ax // 충전 범위 내에 있다면 충전량 return
			int bCharge = check(b_cnt, by, bx);

			sumCharge = aCharge + bCharge;
			if (a_cnt == b_cnt && aCharge > 0 && bCharge > 0)
				sumCharge /= 2;
			maxCharge = max(maxCharge, sumCharge);
		}
	}

	return maxCharge;
}

void solve(int test)
{
	//각 사용자의 시작 위치부터
	//주어진 시간만큼 이동하면서
	//각 단위시간마다 (1,2,3초) 충전량을 누적해서 최종정답 구하는 형태
	int ay=1; int ax=1;
	int by=10; int bx=10;

	for (int t = 0; t <= M; ++t)
	{
		ans += calc(ay, ax, by, bx);

		ay += ydir[alist[t]];
		ax += xdir[alist[t]];

		by += ydir[blist[t]];
		bx += xdir[blist[t]];
	}

	cout << '#' << test << ' ' << ans << '\n';
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