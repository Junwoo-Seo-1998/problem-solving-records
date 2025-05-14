#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;
    for(int i=0; i<arr.size(); ++i)
    {
        if(answer.size() == 0 || *(answer.end()-1) != arr[i])
            answer.push_back(arr[i]);
    }
    return answer;
}