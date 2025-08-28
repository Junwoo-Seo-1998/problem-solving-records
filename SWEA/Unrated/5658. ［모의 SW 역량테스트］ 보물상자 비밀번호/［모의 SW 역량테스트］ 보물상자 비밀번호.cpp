#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
#include<array>
#include<deque>
#include<string>
#include<set>
using namespace std;

string password;
set<string, greater<>> possible;

int N;
int K;
void init()
{
	password.clear();
}

void input()
{
	cin >> N;
	cin >> K;

	cin >> password;
	password += password;

	possible.clear();
}

void solve(int t)
{
	int edge = N / 4;

	for (int i = 0; i < N; ++i)
		possible.insert(password.substr(i, N / 4));

	vector<int> vec;
	for (auto& p : possible)
		vec.push_back(stoi(p, nullptr, 16));
	//sort(vec.begin(), vec.end(), std::greater<int>());

	cout << "#" << t << " ";
	cout << vec[K-1] << endl;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;

	for (int test = 1; test <= T; ++test)
	{
		init();
		input();
		solve(test);
	}


	return 0;
}