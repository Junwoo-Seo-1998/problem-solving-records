#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
명확한 선택 어려움

자리수 6자리

최대 교환 횟수 10번

6c2 조합

15가지

5-6번 정도 교환해보면 최대 값 만들 수 있다.

15 * 15 …..15(15가 6개 6자리니까) = 11,390,625 가능(1100만 정도)

1. 입력
2. 재귀 설계
3. 예외 조건 처리
- 동일한 위치 교환이 중복 되어도 된다.

교환중복이 된다는것의 포인트는

32888 10 일때

이미 최대값이 나왔음에도

교환 횟수가 더 남아있을 때,

1. 불필요한 8번의 교환을 제외
즉, 남아 있는 횟수가 짝수번이면 정답처리
- 만약 홀수번 남아있다면?
88832 (가장 큰 수가 여러개인 경우)
가장 큰수끼리 바꾼다
87632  (가장 큰 수가 하나인 경우)
가장 끝의 두개 숫자를 바꾼다

2번이면 최대값이 된다.

굳이 10번 돌릴 필요는 없다.

88832(2) 가 나오면 동일한 위치 아무거나 바꾸는것을도 정답이됨, 그러므로 바로 정답처리
*/


string s;//원본 문자열
string answer;//기저 조건용
int times;//교환횟수
int ans;
bool flag;

int isTwoComputed = -1;

void init() {
	ans = -1;
	isTwoComputed = -1;
	flag = false;
}

void input()
{
	cin >> s >> times;

	//입력 받은 문자열중에서 생성 할 수 있는 최대 값을 미리 저장해둔다.
	//재귀 코드에서 기저 조건으로 사용

	answer = s;
	sort(answer.begin(), answer.end(), greater<>());
}

bool isTwo(const string& s)
{
	if (isTwoComputed != -1)
		return isTwoComputed;

	bool visited[10] = { 0, };//index: 어떤 숫자 val 중복여부
	int num = 0;
	for (int i = 0; i < s.size(); i++)
	{
		num = s[i]-'0';
		if (visited[num] == true)
			return isTwoComputed = true;
		visited[num] = true;
	}

	return isTwoComputed = false;//중복 x 
}

// 교환되는 문자열, 몇번째
//중요한건 이거는 N^2 되면 터지므로 꼭 NC_2 로 구현해야됨
void dfs(string& s, int cnt)
{
	if (flag) return; //이미 정답 찾음
	//기저
	//1
	if (s == answer)
	{
		//정답을 찾았는데, 남은 횟수가 있는 경우
		int left = times - cnt;
		if (left % 2 == 0) //짝수번 남은 경우
		{
			ans = stoi(s);
			flag = true;
			return;
		}
		else
		{
			if (isTwo(s))//같은 수가 2개 이상인가?
			{
				ans = stoi(s);
				flag = true;
				return;
			}
			else
			{//중복 숫자 없는 경우
				swap(*s.rbegin(), *(s.rbegin() + 1));
				ans = stoi(s);
				flag = true;
				return;
			}
		}
	}

	//2
	//주어진 횟수만큼 교환함
	if (cnt >= times)
	{
		ans = max(ans, stoi(s));
		return;
	}

	//재귀 조건 N^2 안되게 해야함

	for (int i = 0; i < s.size()-1; ++i)//두개 선택이니까 마지막 선택하면 다음꺼는 선택 불가능 사이즈 밖을 선택 불가능
	{
		for (int j = i+1; j < s.size(); ++j)//선택한거 이외의 것을 선택해야함
		{
			swap(s[i], s[j]);
			dfs(s, cnt + 1);
			swap(s[j], s[i]);
		}
	}
}

void solve(int test)
{
	dfs(s, 0);// 교환 문자열, 몇번째

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