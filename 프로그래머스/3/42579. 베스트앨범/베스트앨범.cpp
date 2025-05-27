#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, int> genre_total_play;
    unordered_map<string, vector<pair<int, int>>> genre_songs;

    for (int i = 0; i < genres.size(); ++i) {
        genre_total_play[genres[i]] += plays[i];
        genre_songs[genres[i]].emplace_back(i, plays[i]);
    }

    vector<pair<string, int>> sorted_genres(genre_total_play.begin(), genre_total_play.end());
    sort(sorted_genres.begin(), sorted_genres.end(),
         [](auto& a, auto& b) { return a.second > b.second; });

    vector<int> answer;

    for (auto& [genre, _] : sorted_genres) {
        auto& songs = genre_songs[genre];

        sort(songs.begin(), songs.end(),
             [](auto& a, auto& b) {
                 if (a.second == b.second) return a.first < b.first;
                 return a.second > b.second;
             });

        for (int i = 0; i < songs.size() && i < 2; ++i) {
            answer.push_back(songs[i].first);
        }
    }

    return answer;
}
