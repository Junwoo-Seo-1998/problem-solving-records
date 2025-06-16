#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> player_ranks;
    for (int i = 0; i < players.size(); ++i) {
        player_ranks[players[i]] = i;
    }

    for (const string& calling_player : callings) {
        int current_rank = player_ranks[calling_player];
        
        int front_rank = current_rank - 1;
        string front_player = players[front_rank];
        
        swap(players[current_rank], players[front_rank]);
        
        player_ranks[calling_player] = front_rank;
        player_ranks[front_player] = current_rank;
    }
    
    return players;
}