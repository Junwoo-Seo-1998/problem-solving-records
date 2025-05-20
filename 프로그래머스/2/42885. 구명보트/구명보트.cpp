#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    std::sort(people.begin(), people.end());
    int answer = 0;
    int left=0;
    int right=people.size()-1;
    while(left<=right)
    {
        if(limit>=people[left]+people[right])
            ++left;
        --right;
        
        ++answer;
    }
    return answer;
}