#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;
    vector<int> count(10, 0);

    for (int i = 0; i < priorities.size(); ++i) {
        q.push({i, priorities[i]});
        count[priorities[i]]++;
    }

    int print_order = 0;

    while (!q.empty()) {
        auto [idx, priority] = q.front(); 
        q.pop();

        int max_priority = 9;
        while (count[max_priority] == 0) max_priority--;

        if (priority < max_priority) {
            q.push({idx, priority}); 
        } else {
            print_order++;
            count[priority]--;

            if (idx == location)
                return print_order;
        }
    }

    return -1;
}
