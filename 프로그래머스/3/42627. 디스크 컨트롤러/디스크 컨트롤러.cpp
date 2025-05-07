#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    std::sort(jobs.begin(), jobs.end(), [](auto& lhs, auto& rhs) {
        if (lhs[0] == rhs[0])
        {
            return lhs[1] < rhs[1];
        }
        return lhs[0] < rhs[0];
    });

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    int idx = 0, now = jobs[idx][0];
    pq.push({jobs[idx][1], jobs[idx][0]});
    idx++;
    while (!pq.empty())
    {
        auto [duration, start] = pq.top();
        pq.pop();

        answer += now - start;
        answer += duration;

        now += duration;

        while (idx < jobs.size() && jobs[idx][0] <= now)
        {
            pq.push({jobs[idx][1], jobs[idx][0]});
            idx++;
        }

        if (pq.empty() && idx < jobs.size())
        {
            pq.push({jobs[idx][1], jobs[idx][0]});
            now = jobs[idx][0];
            idx++;
        }
    }

    return answer / jobs.size();
}