#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
#include<array>
#include<deque>
#include<string>
#include<set>
#include<limits>
using namespace std;

struct minIndex
{
	long long minVal = 0;
	int index = 0;
	bool operator<(const minIndex& right) const
	{
		return minVal < right.minVal;
	}
};

struct segTree
{
	int size;
	vector<minIndex> data;
	segTree(int size)
		:size(size), data(2 * size)
	{}

	void build()
	{
		int cur = size - 1;
		while (cur)
		{
			data[cur] = min(data[cur << 1], data[cur << 1 | 1]);
			--cur;
		}
	}

	long long& operator[](int idx)
	{
		data[size + idx].index = idx;
		return data[size + idx].minVal;
	}

	minIndex query(int left, int right)
	{
		left += size;
		right += size;

		minIndex result = { numeric_limits<long long>::max(), -1 };
		for (; left != right; left >>= 1, right >>= 1)
		{
			if (left & 1)
				result = min(result, data[left++]);
			if (right & 1)
				result = min(result, data[--right]);
		}

		return result;
	}
};

long long maxFound = 0;

void findMax(segTree& minTree, int left, int right)
{
	if (left >= right) return;

	auto mLR = minTree.query(left, right);
	maxFound = max(mLR.minVal*(long long)(right - left), maxFound);

	findMax(minTree, left, mLR.index);
	findMax(minTree, mLR.index + 1, right);
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
	int N;
	cin >> N;
	segTree minTree(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> minTree[i];
	}
	minTree.build();
	findMax(minTree, 0, N);
	cout << maxFound << endl;
	return 0;
}