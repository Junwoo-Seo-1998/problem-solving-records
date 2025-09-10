#include<iostream>
#include<cstring>
using namespace std;

int N, M, K;

bool asked[1'002];
int jobs[1'002];
int desire[1'002][1'002];

inline void init()
{
	cin >> N >> M >> K;
	memset(jobs, -1, sizeof(jobs));
	memset(desire, -1, sizeof(desire));

	for (int i = 1; i <= N; ++i)
	{
		int desireCount;
		cin >> desireCount;
		for (int d = 0; d < desireCount; ++d)
		{
			cin >> desire[i][d];
		}
	}
}

inline bool tryToAssign(int person)
{
	for (int jobID : desire[person])
	{
		if (jobID == -1) break;
		if (asked[jobID]) continue;
		asked[jobID] = true;

		if (jobs[jobID] == -1 || tryToAssign(jobs[jobID]))
		{
			jobs[jobID] = person;
			return true;
		}
	}

	return false;
}

inline void solve()
{
	int ans = 0;
	for (int person = 1; person <= N; ++person)
	{
		memset(asked, 0, sizeof(asked));
		if (tryToAssign(person))
		{
			++ans;
		}
	}

	int k = 0;
	for (int person = 1; person <= N; ++person)
	{
		while (true)
		{
			if (k == K) break;

			memset(asked, 0, sizeof(asked));
			if (tryToAssign(person))
			{
				ans++;
				k++;
			}
			else
			{
				break;
			}
		}
		if (k == K) break;
	}

	cout << ans << '\n';
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);

	init();
	solve();

	return 0;
}