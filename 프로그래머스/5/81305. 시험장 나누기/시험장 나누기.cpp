#include <string>
#include <vector>
#include <functional>
#include <numeric>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> num_param, vector<vector<int>> links) {
    int n = num_param.size();

    vector<vector<int>> g(n);
    vector<int> in_degree(n, 0);
    
    long long total_sum_of_people = 0;
    int max_single_node_people = 0; 

    for (int i = 0; i < n; ++i) {
        total_sum_of_people += num_param[i];
        max_single_node_people = max(max_single_node_people, num_param[i]);

        if (links[i][0] != -1) {
            g[i].push_back(links[i][0]);
            in_degree[links[i][0]]++;
        }
        if (links[i][1] != -1) {
            g[i].push_back(links[i][1]);
            in_degree[links[i][1]]++;
        }
    }

    int root = -1;
    for (int i = 0; i < n; ++i) {
        if (in_degree[i] == 0) {
            root = i;
            break;
        }
    }


    function<int(int, int, int, int&)> solve_dfs = 
        [&](int u, int p, int limit, int& current_cuts) -> int {
        
        if (num_param[u] > limit) {
            current_cuts = k + 100; 
            return num_param[u];
        }

        int current_node_sum_to_pass_up = num_param[u];
        vector<int> child_sums_from_branches;

        for (int v : g[u]) {
            if (v == p) continue;

            int child_contribution = solve_dfs(v, u, limit, current_cuts);
            if (current_cuts >= k) { 
                 return current_node_sum_to_pass_up; 
            }
            child_sums_from_branches.push_back(child_contribution);
        }

        sort(child_sums_from_branches.begin(), child_sums_from_branches.end());

        for (int child_s : child_sums_from_branches) {
            if (current_node_sum_to_pass_up + child_s <= limit) {
                current_node_sum_to_pass_up += child_s;
            } else {
                current_cuts++; 
            }
        }
        return current_node_sum_to_pass_up; 
    };


    int l = max_single_node_people;
    int r = total_sum_of_people;
    int ans = r;

    if (k == 1) return total_sum_of_people; 

    while (l <= r) {
        int mid = (l+r) / 2;
        
        int cuts_needed = 0;
        solve_dfs(root, -1, mid, cuts_needed);

        if (cuts_needed < k) { 
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    
    return ans;
}