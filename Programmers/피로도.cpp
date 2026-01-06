#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer; 
vector<bool> visited;

void dfs(int k, vector<vector<int>> dungeons, int cnt) {
    answer = max(answer, cnt);
    
    for (int i = 0; i < dungeons.size(); i++) {
        if (!visited[i] && k >= dungeons[i][0]) {
            visited[i] = true;
            dfs(k - dungeons[i][1], dungeons, cnt + 1);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    visited.resize(dungeons.size() + 1, false);
    dfs(k, dungeons, 0);
    
    return answer;
}
