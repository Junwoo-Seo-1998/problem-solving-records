#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q; // (index, priority)
    priority_queue<int> pq;  // max heap

    for (int i = 0; i < priorities.size(); ++i) {
        q.push({i, priorities[i]});
        pq.push(priorities[i]);
    }

    int order = 0;

    while (!q.empty()) {
        auto [idx, prio] = q.front(); q.pop();

        // 현재 우선순위가 최고인지 확인
        if (prio == pq.top()) {
            pq.pop();
            order++;
            if (idx == location)
                return order;
        } else {
            q.push({idx, prio});  // 다시 뒤로
        }
    }

    return -1;
}