#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    unordered_map<string, int> um;
    
    for (int i = 0; i < players.size(); i++) {
        um.insert({players[i], i});
    }
    
    for (auto name : callings) {
        int idx = um[name];
        um[name] -= 1;
        um[players[idx-1]] += 1;
        
        swap(players[idx], players[idx-1]);
    }
    answer = players;
    
    return answer;
}

// 해시맵 (이름, 현재 인덱스) 저장
// 바로 앞 사람 players[idx-1]
// swap하기 
