#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;
vector<bool> visited;       // 초기화 해야 함

void backtracking(int depth, vector<vector<int>>& ability, int sum) 
{
    int sports = ability[0].size();
    int students = ability.size();
    
    if (depth == sports) {
        answer = max(answer, sum);
        return;
    }
    
    for (int i = 0; i < students; i++) {
        if (!visited[i]) {
            visited[i] = true;
            backtracking(depth + 1, ability, sum + ability[i][depth]);
            visited[i] = false;
        }
    }
}

int solution(vector<vector<int>> ability) {    
    visited.assign(ability.size(), false);
    backtracking(0, ability, 0);
    
    return answer;
}
