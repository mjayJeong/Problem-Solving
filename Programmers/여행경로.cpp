#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;
vector<bool> used;
bool finished = false;

void dfs(string cur, vector<vector<string>>& tickets, vector<string>& path, int cnt) {
    if (finished) return;
    
    if (cnt == tickets.size()) {
        answer = path;
        finished = true;
        return;
    }
    
    for (int i = 0; i < tickets.size(); i++) {
        if (!used[i] && tickets[i][0] == cur) {
            used[i] = true;
            path.push_back(tickets[i][1]);
            
            dfs(tickets[i][1], tickets, path, cnt+1);
            
            path.pop_back();
            used[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());   // 정렬 먼저
    
    used.resize(tickets.size(), false);
    
    vector<string> path;
    path.push_back("ICN");
    
    dfs("ICN", tickets, path, 0);
    
    return answer;
}
