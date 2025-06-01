#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;

    std::vector<bool> visit(tickets.size(), false);

    std::sort(tickets.begin(), tickets.end(), [](auto lhs, auto rhs) {
        if (lhs[0] == rhs[0])
        {
            return lhs[1] < rhs[1];
        }

        return lhs[0] < rhs[0];
    });

    std::function<bool(std::string)> dfs = [&](std::string target) {

        std::vector<std::string> t = { target, "" };
        auto it = std::lower_bound(tickets.begin(), tickets.end(), t, [](auto& lhs, auto& rhs) {
            return lhs[0] < rhs[0];
        });
        int next = std::distance(tickets.begin(), it);

        answer.push_back(target);
        while (next < tickets.size() && tickets[next][0] == target)
        {
            if (!visit[next])
            {
                visit[next] = true;
                if (dfs(tickets[next][1]))
                {
                    break;
                }
                visit[next] = false;
            }
            next++;
        }

        if (tickets.size() + 1 == answer.size())
        {
            return true;
        }

        answer.pop_back();
        return false;
    };

    dfs("ICN");

    return answer;
}