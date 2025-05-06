#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int sz = citations.size();
    sort(citations.rbegin(), citations.rend());
    for(int i = 0 ; i < sz; i++){
        if(citations[i]>i) answer++;
        else return answer;
    }
    return answer;
}