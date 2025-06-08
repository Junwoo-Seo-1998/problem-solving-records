#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    answer.reserve(id_list.size());
    unordered_map<string, unordered_set<string>> acc;
    unordered_map<string, unordered_set<string>> mail;
    
    for(auto& s:report)
    {
        auto iter=s.find_first_of(' ');
        auto id=s.substr(0, iter);
        auto target=s.substr(iter+1);
        
        auto& report_set=acc[target];
        report_set.insert(id);
        if(report_set.size()>=k)
        {
            for(auto& to_report:report_set)
            {
                mail[to_report].insert(target);
            }
        }
    }
    for(auto& s:id_list)
    {
        answer.push_back(mail[s].size());
    }
    
    return answer;
}