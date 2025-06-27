#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int last=0;
    for(int s:section)
    {
        if(s>last)
        {
            ++answer;
            last=s+m-1;
        }
    }
    
    return answer;
}