#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    
    for(int i=1; i*i<=yellow; ++i)
    {
        if(yellow%i==0)
        {
            int w=yellow/i;
            if((2*(w+i)+4)==brown)
            {
                return {w+2, i+2};
            }
        }
    }
    vector<int> answer;
    return answer;
}