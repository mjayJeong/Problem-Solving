#include <string>
#include <vector>

using namespace std;

string solution(string input_string) {
    string answer = "";
    
    int n = input_string.size();
    
    vector<int> cnt(26, 0);
    
    for (int i = 0; i < n; i++) {
        if (i == 0 || input_string[i] != input_string[i-1]) {
            cnt[input_string[i] - 'a']++;
        }
    }
    
    for (int i = 0; i < 26; i++) {
        if (cnt[i] >= 2) {
            answer += char(i + 'a');
        }
    }
    
    if (answer.size() == 0) return "N";
    
    return answer;
}
