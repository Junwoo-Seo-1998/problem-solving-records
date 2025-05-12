#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int solution(string word) {
    int answer = 0;
    int behind[5]={781, 156, 31, 6, 1};
    std::unordered_map<char, int> map;
    
    map['A']=0;
    map['E']=1;
    map['I']=2;
    map['O']=3;
    map['U']=4;

    for(int i=0; i<word.size(); ++i)
    {
        answer+=behind[i]*map[word[i]]+1;    
    }
    
    return answer;
}