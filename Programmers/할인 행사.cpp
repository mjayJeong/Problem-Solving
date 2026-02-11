#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int answer;
unordered_map<string, int> um;

// 해시맵에 원하는게 다 있는지 확인 
bool check(vector<string>& want, vector<int>& number) {
    for (int i = 0; i < want.size(); i++) {
        if (um[want[i]] != number[i]) {
            return false;   // 개수 다르면 false
        }
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int left = 0, right = 9;
    um.clear();
    
    // 처음에 삽입
    for (int i = 0; i < 10; i++) {
        um[discount[i]]++;
    }
    
    while (true) {
        if (check(want, number)) answer++;
        
        // 다음 윈도우가 없으면 종료
        if (right + 1 >= discount.size()) break;
        
        um[discount[left]]--;
        left++;
        right++;
        um[discount[right]]++;
    }
    
    return answer;
}
