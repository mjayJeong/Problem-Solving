#include <string>
#include <vector>

using namespace std;

vector<string> dict;
string vowels[5] = {"A", "E", "I", "O", "U"};

void dfs(string str, int len) {
    dict.push_back(str);
    if (len == 5) return;
    
    for (int i = 0; i < 5; i++) {
        dfs(str + vowels[i], len+1);
    }
}


int solution(string word) {
    int answer = 0;
    
    dfs("", 0);
    
    while (true) {
        if (dict[answer] == word) {
            break;
        }
        answer++;
    }
    
    return answer;
}
