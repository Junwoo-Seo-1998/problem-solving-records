#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    
    
    int prev11=0;
    int prev12=0;

    int prev01=0;
    int prev02=0;
    for(int i=1; i<money.size(); i++)
    {
        int temp1=prev11;
        prev11=max(prev12+money[i],prev11);
        prev12=temp1;

        int temp2=prev01;
        prev01=max(prev02+money[i-1],prev01);
        prev02=temp2;
    }
    return max(prev01,prev11);
}