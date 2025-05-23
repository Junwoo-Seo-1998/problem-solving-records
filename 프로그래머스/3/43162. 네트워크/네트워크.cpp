#include <string>
#include <vector>
#include <functional>
#include <set>
using namespace std;




int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> p;
    for(int i=0; i<n; ++i)
        p.push_back(i);
    std::function<int(int)> getParent=[&](int index)->int
    {
        if(p[index]==index)
            return index;
        p[index]=getParent(p[index]);
        return p[index];
    };
    
    auto merge=[&](int left, int right){
        int leftP=getParent(left);
        int rightP=getParent(right);
        
        if(leftP==rightP)
            return;
        else if(leftP<rightP)
            p[rightP]=leftP;
        else
            p[leftP]=rightP;
    };
    
    for(int from=0; from<n; ++from)
    {
        for(int to=0; to<n; ++to)
        {
            if(computers[from][to]==1)
            {
                merge(from, to);      
            }
        }
    }
    
    set<int> s;
    for(int i=0; i<n; ++i)
        s.insert(getParent(i));
    return s.size();
}