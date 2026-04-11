#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> location(26, -1);
    
    for (int i = 0; i < s.size(); i++) {
        if (location[s[i] - 'a'] == -1) {
            answer.push_back(-1);
            location[s[i] - 'a'] = i;
        }
        else { 
            answer.push_back(i - location[s[i] - 'a']);
            location[s[i] - 'a'] = i;
        }
    }
    
    return answer;
}

// 카운팅 배열 이용 -> 개수 대신 위치 저장 
