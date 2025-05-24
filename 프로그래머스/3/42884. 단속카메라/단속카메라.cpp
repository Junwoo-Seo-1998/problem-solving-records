#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end(), [](const vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
    });
    int camera=-30001;
    int answer = 0;
    
     for (const auto& route : routes) 
     {
        if (route[0] > camera) 
        {
            camera = route[1];
            answer++;
        }
    }
    
    return answer;
}