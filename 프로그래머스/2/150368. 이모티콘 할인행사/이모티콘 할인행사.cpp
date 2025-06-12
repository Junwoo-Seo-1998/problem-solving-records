#include <string>
#include <vector>
#include <functional>
using namespace std;

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    pair<int, int> answer(-1, -1);
    
    int discounts[4]={40, 30, 20, 10};
    
    vector<int> record(emoticons.size(), 0);
    function<void(int)> func=[&](int current)
    {

        if(current==record.size())
        {
            int total_enroll=0;
            int total_price=0;
            for(auto& user:users)
            {
                int price=0;
                bool enroll=false;
                for(int i=0; i<record.size(); ++i)
                {
                    if(record[i]>=user[0])
                    {
                        price+=emoticons[i]*(100-record[i])/100;
                        if(price>=user[1])
                        {
                            enroll=true;
                            break;
                        }
                    }
                }
                
                enroll ? ++total_enroll : total_price+=price;    
            }
            
            answer=max(answer, {total_enroll, total_price});
            
            return;
        }
        
        for(int discount:discounts)
        {
            record[current]=discount;       
            func(current+1);    
        }
    };
    
    func(0);
    return {answer.first, answer.second};
}