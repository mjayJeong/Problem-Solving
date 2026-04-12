#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    vector<bool> alpha(26, false);
    for (int i = 0; i < skip.size(); i++) {
        alpha[skip[i] - 'a'] = true;
    }
    
    for (int i = 0; i < s.size(); i++) {
        int cur = s[i] - 'a';
        int cnt = 0;
        
        while (cnt < index) {
            cur = (cur + 1) % 26;
            if (!alpha[cur]) {
                cnt++;
            }
        }
        
        answer += char(cur + 'a');
    }
    
    return answer;
}
