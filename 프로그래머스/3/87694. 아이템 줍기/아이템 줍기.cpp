#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    constexpr int MAX_COORD_VAL = 50;
    constexpr int MAX_SIZE = MAX_COORD_VAL * 2 + 2; 

    vector<vector<int>> board(MAX_SIZE, vector<int>(MAX_SIZE, 0));

    for (const auto& rect : rectangle) {
        int x1 = rect[0] * 2;
        int y1 = rect[1] * 2;
        int x2 = rect[2] * 2;
        int y2 = rect[3] * 2;

        for (int current_y = y1; current_y <= y2; ++current_y) {
            for (int current_x = x1; current_x <= x2; ++current_x) {
                board[current_y][current_x] = 1;
            }
        }
    }

    for (const auto& rect : rectangle) {
        int x1 = rect[0] * 2;
        int y1 = rect[1] * 2;
        int x2 = rect[2] * 2;
        int y2 = rect[3] * 2;

        for (int current_y = y1 + 1; current_y < y2; ++current_y) {
            for (int current_x = x1 + 1; current_x < x2; ++current_x) {
                board[current_y][current_x] = 0;
            }
        }
    }

    int startX_bfs = characterX * 2;
    int startY_bfs = characterY * 2;
    int targetX_bfs = itemX * 2;
    int targetY_bfs = itemY * 2;

    queue<tuple<int, int, int>> q;
    q.push({startY_bfs, startX_bfs, 0}); 

    vector<vector<int>> dist_map(MAX_SIZE, vector<int>(MAX_SIZE, -1));
    dist_map[startY_bfs][startX_bfs] = 0;

    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    while (!q.empty()) {
        auto [curr_y, curr_x, current_dist] = q.front();
        q.pop();

        if (curr_y == targetY_bfs && curr_x == targetX_bfs) {
            return current_dist / 2;
        }

        for (int i = 0; i < 4; ++i) {
            int ny = curr_y + dy[i];
            int nx = curr_x + dx[i];

            if (nx >= 0 && nx < MAX_SIZE && ny >= 0 && ny < MAX_SIZE) {
                if (board[ny][nx] == 1 && dist_map[ny][nx] == -1) {
                    dist_map[ny][nx] = current_dist + 1;
                    q.push({ny, nx, current_dist + 1});
                }
            }
        }
    }

    return -1; 
}