#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

//값이 사람 id
int jobs[1001];
bool asked[1001];
int N, M;
int K;

vector<vector<int>> desire;

void dbgPrint()
{
	for (int i = 0; i < M; ++i)
	{
		cout << jobs[i] << " ";
	}
	cout << "\n";
}

bool couldGetAJob(int personID)
{
	for (int jobID : desire[personID])
	{
		if (jobID == -1) break;
		if (asked[jobID]) continue;
		asked[jobID] = true;

		if (jobs[jobID] == -1 || couldGetAJob(jobs[jobID]))
		{
			jobs[jobID] = personID;
			return true;
		}
	}


	return false;
}

void init() 
{
	memset(jobs, -1, sizeof(jobs));
	desire.assign(1000, vector<int>(1000, -1));
}

void input()
{
	cin >> N >> M >> K;

	for (int i = 0; i < N; ++i)
	{
		int J = 0;
		cin >> J;
		for (int j = 0; j < J; ++j)
		{
			int temp;
			cin >> temp;
			desire[i][j] = temp - 1;
		}
	}

}

void solve()
{
	int ans = 0;
	for (int person = 0; person < N; ++person)
	{
		memset(asked, 0, sizeof(asked));
		if (couldGetAJob(person))
			ans++;

		//dbgPrint();
	}

	int k = 0;
	for (int person = 0; person < N; ++person)
	{
		memset(asked, 0, sizeof(asked));
		if (couldGetAJob(person))
		{
			ans++;
			k++;
		}
		//dbgPrint();
		if (k == K)
			break;
	}

	cout << ans << '\n';
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	init();
	input();
	solve();

	return 0;
}