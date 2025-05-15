#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    for(int current=triangle.size()-1; current>0; --current )
    {
        for(int i=0; i<triangle[current].size()-1; ++i)
        {
            triangle[current-1][i]+=max(triangle[current][i], triangle[current][i+1]);
        }
    }
    return triangle[0][0];                   
}