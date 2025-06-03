#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;


vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    unordered_map<char, int> exp;
    
    for(auto& term: terms)
    {
        string date=term.substr(2);
        exp[term[0]]=stoi(date);
    }
    
    
     auto expire=[&](char term, string& date)
    {
        int year=stoi(date.substr(0, 4));
        int month=stoi(date.substr(5,7));
        int day=stoi(date.substr(8,10));
        
        year+=exp[term]/12;
        month+=exp[term]%12;
        
        if(month>12)
        {
            year+=1;
            month-=12;
        }
        
        
        string sM=to_string(month);
        string sD=to_string(day);
        string fin=to_string(year)+"."+string(2-sM.length(), '0')+sM+"."+string(2-sD.length(), '0')+sD;
        //cout<<fin<<"\n";
        return fin<=today;
    };
    
    for(int i=0; i<privacies.size(); ++i)
    {
        string date=privacies[i].substr(0, 10);
        char term=privacies[i][11];
        if(expire(term, date))
        {
            answer.push_back(i+1);
        }
    }
    
    return answer;
}