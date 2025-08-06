#include <string>
#include <vector>

using namespace std;

bool visited[51];
int answer = 0; 

void dfs(string begin, string target, vector<string> words, int cnt) {
    if (begin == target) {
        answer = cnt;
        return;
    }
    for (int i = 0; i < words.size(); i++) {
        if (visited[i]) {
            continue;
        }
        
        int k = 0;
        for (int j = 0; j < begin.length(); j++) {
            if (begin[j] == words[i][j]) {
                k++;
            }
        }
        if (k == begin.length() - 1) {
            visited[i] = true;
            dfs(words[i], target, words, cnt+1);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    
    dfs(begin, target, words, 0);
    
    return answer;
}
