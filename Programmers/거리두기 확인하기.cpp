#include <string>
#include <vector>
#include <cmath>

using namespace std;

int get_distance(pair<int, int>& a, pair<int, int>& b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

bool check_location(pair<int, int>& a, pair<int, int>& b, vector<string>& places)
{
    if (a.first == b.first) {
        int mid = (a.second + b.second) / 2;
        if (places[a.first][mid] != 'X') return false;
    }
    else if (a.second == b.second) {
        int mid = (a.first + b.first) / 2;
        if (places[mid][a.second] != 'X') return false;
    }
    else {
        if (places[a.first][b.second] == 'X' && places[b.first][a.second] == 'X') return true;
        else return false;
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (int i = 0; i < 5; i++) {
        vector<pair<int, int>> people;

        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (places[i][j][k] == 'P') {
                    people.push_back({j, k});
                }
            }
        }
        
        bool flag = true;

        for (int j = 0; j + 1 < people.size(); j++) {
            if (!flag) break;

            for (int k = j + 1; k < people.size(); k++) {
                int dist = get_distance(people[j], people[k]);
                
                if (dist > 2) continue;

                if (dist == 2) {
                    if (!check_location(people[j], people[k], places[i])) {
                        answer.push_back(0);
                        flag = false;
                        break;
                    }
                } 
                else { // dist == 1
                    answer.push_back(0);
                    flag = false;
                    break;
                }
            }
        }

        if (flag) answer.push_back(1);
    }
    
    return answer;
}
