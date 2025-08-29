#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;
int N, C;

vector<int> pos;


//dist 거리를 최소로 할때 C개를 둘수있는지?
bool canPlace(int dist)
{
	int count = 1;
	int last_pos = pos[0];

	for (int i = 1; i < N; ++i)
	{
		if (pos[i] - last_pos >= dist)
		{
			count++; 
			if (count >= C)
				return true;
			last_pos = pos[i];
		}
	}
	return count >= C;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> N >> C;

	pos.assign(N, 0);

	for (int i = 0; i < N; ++i)
		cin >> pos[i];

	sort(pos.begin(), pos.end());

	int left = 1; int right = pos[N-1] - pos[0];
	

	int found = 0;
	while (left<=right)
	{
		int dist = (left + right) / 2;

		if (canPlace(dist))
		{
			left = dist + 1;
			found = dist;
		}
		else
		{
			right = dist - 1;
		}
	}
	cout << found << '\n';

	return 0;
}