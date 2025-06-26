#include <string>
#include <vector>
#include <algorithm> // std::min, std::max를 사용하기 위해 필요

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    int min_row = 51, min_col = 51;
    int max_row = -1, max_col = -1;

    for (int i = 0; i < wallpaper.size(); ++i) {
        for (int j = 0; j < wallpaper[i].size(); ++j) {
            if (wallpaper[i][j] == '#') {
                min_row = min(min_row, i);
                min_col = min(min_col, j);
                max_row = max(max_row, i);
                max_col = max(max_col, j);
            }
        }
    }

    vector<int> answer = {min_row, min_col, max_row + 1, max_col + 1};
    
    return answer;
}