#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    vector<int> min_cnt(26, INF);
    
    for (int i = 0; i < keymap.size(); i++) {
        for (int j = 0; j < keymap[i].size(); j++) {
            int idx = keymap[i][j] - 'A';
            min_cnt[idx] = min(min_cnt[idx], j + 1);
        }
    }
    
    for (int i = 0; i < targets.size(); i++) {
        int sum = 0;
        bool possible = true;

        for (int j = 0; j < targets[i].size(); j++) {
            int idx = targets[i][j] - 'A';

            if (min_cnt[idx] == INF) {
                possible = false;
                break;
            }

            sum += min_cnt[idx];
        }

        if (possible) answer.push_back(sum);
        else answer.push_back(-1);
    }
    
    return answer;
}
