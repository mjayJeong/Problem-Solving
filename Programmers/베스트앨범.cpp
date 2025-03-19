#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, int> genrePlayCount; 
    unordered_map<string, vector<pair<int, int>>> genreSongs; 

    for (int i = 0; i < genres.size(); i++) {
        genrePlayCount[genres[i]] += plays[i]; 
        genreSongs[genres[i]].push_back({plays[i], i}); 
    }

    vector<pair<int, string>> sortedGenres;
    for (auto& g : genrePlayCount) {
        sortedGenres.push_back({g.second, g.first}); 
    }
    sort(sortedGenres.rbegin(), sortedGenres.rend());

    vector<int> answer;

    for (auto& genre : sortedGenres) {
        string g = genre.second;
        
        auto& songs = genreSongs[g];
        sort(songs.begin(), songs.end(), [](pair<int, int> a, pair<int, int> b) {
            if (a.first == b.first) return a.second < b.second; 
            return a.first > b.first; 
        });

        answer.push_back(songs[0].second);
        if (songs.size() > 1) {
            answer.push_back(songs[1].second);
        }
    }

    return answer;
}
