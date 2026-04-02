#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<string> us;

bool is_valid(string& prev, string& cur)
{
    // 올바른 시작 체크
    if (prev[prev.size() - 1] != cur[0]) return false;
    
    // 이미 사용 단어 체크
    if (us.find(cur) != us.end()) {
        return false;
    }
    
    return true;
}

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int turn = 1;
    
    us.insert(words[0]);
    for (int i = 1; i < words.size(); i++) {
        if (!is_valid(words[i-1], words[i])) {
            int person = (i % n) + 1;
            int turn = (i / n) + 1;
            
            return {person, turn};
        }
        us.insert(words[i]);
    }

    return {0, 0};
}
