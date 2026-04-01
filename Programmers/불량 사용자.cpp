#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<vector<string>> cases;

// 일치하는지 체킹하는 함수
bool match(const string& user, const string& banned) {
    if (user.size() != banned.size()) return false;
    
    for (int i = 0; i < user.size(); i++) {
        if (banned[i] == '*') continue;
        
        if (user[i] != banned[i]) return false;
    }
    return true;
}

void dfs(int idx, vector<string>& user_id, vector<string>& banned_id, vector<bool>& used, vector<string>& selected) {
    
    // 밴 아이디 만큼 돌면 종료
    if (idx == banned_id.size()) {
        vector<string> temp = selected;
        sort(temp.begin(), temp.end());
        cases.insert(temp);
        return; 
    }
    
    for (int i = 0; i < user_id.size(); i++) {
        if (used[i]) continue;
        if (!match(user_id[i], banned_id[idx])) continue;
        
        used[i] = true;
        selected.push_back(user_id[i]);
        
        dfs(idx + 1, user_id, banned_id, used, selected);
        
        selected.pop_back();
        used[i] = false;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    vector<bool> used(user_id.size(), false);
    vector<string> selected;
    
    dfs(0, user_id, banned_id, used, selected);
    
    return cases.size();
}
