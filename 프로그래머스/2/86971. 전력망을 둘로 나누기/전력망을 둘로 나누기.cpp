#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;

vector<int> parent;
vector<int> groupSize;


int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx != ry) {
        parent[ry] = rx;
        groupSize[rx] += groupSize[ry];
    }
}

int solution(int n, vector<vector<int>> wires) {
    int minDiff = n;

    for (int i = 0; i < wires.size(); ++i) {
        parent.assign(n + 1, 0);
        groupSize.assign(n + 1, 1);
        for (int j = 1; j <= n; ++j) {
            parent[j] = j;
        }

        // i번째 전선을 끊고 나머지로 Union 수행
        for (int j = 0; j < wires.size(); ++j) {
            if (i == j) continue;
            int a = wires[j][0];
            int b = wires[j][1];
            unite(a, b);
        }

        // 그룹 크기 계산
        unordered_map<int, int> group;
        for (int k = 1; k <= n; ++k) {
            int root = find(k);
            group[root]++;
        }

        // 두 그룹의 차이 계산
        if (group.size() == 2) {
            auto it = group.begin();
            int a = it->second;
            ++it;
            int b = it->second;
            minDiff = min(minDiff, abs(a - b));
        }
    }

    return minDiff;
}
