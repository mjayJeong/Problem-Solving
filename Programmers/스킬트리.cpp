#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    // skill에 있는 거 카운팅 배열 체크
    vector<int> cnt(26, 0);
    for (int i = 0; i < skill.size(); i++) {
        cnt[skill[i] - 'A']++;
    }
    
    for (int i = 0; i < skill_trees.size(); i++) {
        string tmp = "";
        for (int j = 0; j < skill_trees[i].size(); j++) {
            if (cnt[skill_trees[i][j] - 'A'] >= 1) {
                tmp += skill_trees[i][j];
            }
        }
        
        if (tmp == skill.substr(0, tmp.size())) {
            answer++;
        }
    }
    
    return answer;
}
