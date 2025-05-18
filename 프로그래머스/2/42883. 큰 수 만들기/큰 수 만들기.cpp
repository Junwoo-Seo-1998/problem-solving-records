#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer;;
    for(char c:number)
    {
        while(!answer.empty() && c>*(answer.end()-1) && k>0)
        {
            answer.pop_back();
            k--;
        }
        
        answer.push_back(c);
    }
    
    while(k)
    {
        answer.pop_back();
        k--;
    }
    return answer;
}