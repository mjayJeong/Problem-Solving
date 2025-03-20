#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> gems) {
    unordered_set<string> types(gems.begin(), gems.end());
    int total = types.size();
    
    unordered_map<string, int> gemCount;
    int left = 0, right = 0;
    int min_len = gems.size() + 1;
    vector<int> answer = {1, (int)gems.size()};
    
    while (right < gems.size()) {
        // right 포인터로 확장
        gemCount[gems[right]]++;
        right++;
        
        // 끝까지 모두 넣고 구간 축소
        while (gemCount.size() == total) {
            if (right - left < min_len) {
                min_len = right - left;
                answer = {left + 1, right};  // 진열대 번호는 1번부터 시작
            }
            // 구간 축소 
            gemCount[gems[left]]--;
            if (gemCount[gems[left]] == 0) {
                gemCount.erase(gems[left]);  // 보석 카운트가 0이 되면 반복문 종료 (최소 범위 없데이트 x)
            }
            left++;
        }
    }
    
    return answer;
}
