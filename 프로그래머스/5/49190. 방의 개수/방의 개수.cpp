#include <string>
#include <vector>
#include <set>
#include <utility>   // std::pair 사용
#include <algorithm> // std::swap 사용

using namespace std;

// 간선을 정규화된 형태로 만들기 위한 헬퍼 함수
// 두 정점 u, v를 받아 항상 사전 순으로 앞서는 정점이 first가 되도록 pair를 만듭니다.
pair<pair<int, int>, pair<int, int>> normalize_edge(pair<int, int> u, pair<int, int> v) {
    if (u > v) { // std::pair는 기본적으로 사전식 비교를 지원합니다.
        swap(u, v);
    }
    return {u, v};
}

int solution(vector<int> arrows) {
    pair<int, int> current_pos = {0, 0};
    set<pair<int, int>> visited_nodes;
    set<pair<pair<int, int>, pair<int, int>>> visited_edges;

    visited_nodes.insert(current_pos);

    for (int dir : arrows) {
        
        int X_offset = 0;
        int Y_offset = 0;
        switch(dir) {
            case 0: Y_offset=1; break; case 1: X_offset=1; Y_offset=1; break;
            case 2: X_offset=1; break; case 3: X_offset=1; Y_offset=-1; break;
            case 4: Y_offset=-1; break; case 5: X_offset=-1; Y_offset=-1; break;
            case 6: X_offset=-1; break; case 7: X_offset=-1; Y_offset=1; break;
        }

        for (int i = 0; i < 2; ++i) {
            pair<int, int> prev_pos = current_pos;

            current_pos.first += X_offset;
            current_pos.second += Y_offset;

            visited_nodes.insert(current_pos);

            visited_edges.insert(normalize_edge(prev_pos, current_pos));
        }
    }

    return 1 - visited_nodes.size() + visited_edges.size();
}