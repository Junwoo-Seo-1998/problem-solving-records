#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    constexpr int timeMax=23*60+59;
    
    int defaultTime=fees[0];
    int defaultPrice=fees[1];
    int chargeTime=fees[2];
    int charge=fees[3];
    
    map<string, int> cars;
    unordered_map<string, int> accTime;
    for(auto& r:records)
    {
        int min=stoi(r.substr(0, 2))*60; 
        min+=stoi(r.substr(3, 2));
        auto carNum=r.substr(6, 4);
        bool isIn=r[11]=='I';
        if(isIn)
        {
            cars[carNum]=min;
        }
        else
        {
            accTime[carNum]+=min-cars[carNum];
            cars[carNum]=-1;
        }
    }
    
    vector<int> answer;
    answer.reserve(cars.size());
    
    for(auto& p:cars)
    {
        auto& [carNum, lastTime]=p;
        int time=accTime[carNum];
        if(lastTime!=-1)
            time+=timeMax-lastTime;
        
        int pay=defaultPrice;
        if(time>defaultTime)
        {
            pay+=ceil((time-defaultTime)/(float)chargeTime)*charge;
        }
        answer.push_back(pay);
    }
    return answer;
} 