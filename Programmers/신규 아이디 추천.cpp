#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    // 1단계
    for (int i = 0; i < new_id.size(); i++) {
        if (new_id[i] >= 'A' && new_id[i] <= 'Z') {
            new_id[i] += 32;
        }
    }
    
    // 2단계 
    for (int i = 0; i < new_id.size(); i++) {
        if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9') || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') {
            continue;
        } else {
            new_id.erase(new_id.begin() + i);
            i--;    // 문자열 밀림 방지
        }
    }
    
    // 3단계
    for (int i = 0; i + 1 < new_id.size(); i++) {
        if (new_id[i] == '.' && new_id[i+1] == '.') {
            new_id.erase(new_id.begin() + i);
            i--;
        }    
    }
    
    // 4단계
    if (!new_id.empty() && new_id.front() == '.') new_id.erase(new_id.begin());
    if (!new_id.empty() && new_id.back() == '.') new_id.pop_back();
    
    // 5단계
    if (new_id.empty()) new_id += 'a';
    
    // 6단계
    if (new_id.size() >= 16) {
        new_id.erase(15);
        if (!new_id.empty() && new_id.back() == '.') {      // 마지막 마침표면 제거
            new_id.pop_back();
        }
    }
    
    // 7단계
    if (new_id.size() <= 2) {
        while (new_id.size() != 3) {
            new_id += new_id[new_id.size() - 1];
        }
    }
    
    answer = new_id;
    
    return answer;
}
