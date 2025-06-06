#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    
    vector<vector<int>> diff(board.size()+1, vector<int>(board[0].size()+1, 0));
    
    for(auto& s:skill)
    {
        //[type, r1, c1, r2, c2, degree]
        int r1=s[1];
        int c1=s[2];
        int r2=s[3];
        int c2=s[4];
        int degree= s[0]==1 ? -s[5] : s[5];
        
        diff[r1][c1]+=degree;
        diff[r1][c2+1]-=degree;
        diff[r2+1][c1]-=degree;
        diff[r2+1][c2+1]+=degree;
    }
    
    for (int i=0; i < board.size(); i++) 
        for (int j=1; j < board[0].size(); j++) 
            diff[i][j] += diff[i][j - 1];



    for (int i=0; i < board[0].size(); i++) 
        for (int j=1; j < board.size(); j++) 
            diff[j][i] += diff[j - 1][i];
        
    
    int answer = 0;
    for (int i=0; i < board.size(); i++) 
        for (int j=0; j < board[0].size(); j++) 
        {
            board[i][j] += diff[i][j];
            if(board[i][j]>0)
                ++answer;
        }
    
    return answer;
}