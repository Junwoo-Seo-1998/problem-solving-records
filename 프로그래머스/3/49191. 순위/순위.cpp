#include <vector>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    // 0: 모름, 1: 이김, -1: 짐
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));

    for (auto& r : results) {
        int win = r[0], lose = r[1];
        graph[win][lose] = 1;
        graph[lose][win] = -1;
    }

    //플로이드–워셜: 간접 관계 채우기
    for (int k = 1; k <= n; ++k) {         // 경유
        for (int i = 1; i <= n; ++i) {     // 출발
            for (int j = 1; j <= n; ++j) { // 도착
                if (graph[i][k] == 1 && graph[k][j] == 1)
                    graph[i][j] = 1, graph[j][i] = -1;
                if (graph[i][k] == -1 && graph[k][j] == -1)
                    graph[i][j] = -1, graph[j][i] = 1;
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        int known = 0;
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            if (graph[i][j] != 0) known++;
        }
        if (known == n - 1) answer++;
    }

    return answer;
}
