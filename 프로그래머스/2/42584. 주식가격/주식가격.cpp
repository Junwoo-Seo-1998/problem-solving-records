#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    std::stack<int> s;
    
    s.push(0);
    for(int i=1; i<prices.size(); ++i)
    {
        while (!s.empty() && prices[s.top()] > prices[i]) {
            int topIndex = s.top();
            s.pop();
            answer[topIndex] = i - topIndex;
        }
        s.push(i);

    }
    
    while(!s.empty())
    {
        answer[s.top()]=(prices.size()-1-s.top());
        s.pop();
    }
    return answer;
}