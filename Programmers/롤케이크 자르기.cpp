#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    int left = 0, right = topping.size() - 1;
    
    vector<int> leftCnt(10001, 0), rightCnt(10001, 0);      // 각 구역 카운팅 배열
    set<int> leftKind, rightKind;
    
    // 초기 우측 원소 모두 삽입 
    for (int i = 0; i < topping.size(); i++) {
        if (rightCnt[topping[i]] == 0) {
            rightKind.insert(topping[i]);
        }
        rightCnt[topping[i]]++;
    }
    
    while (left < right) {
        // 오른쪽 하나 제거
        rightCnt[topping[left]]--;
        if (rightCnt[topping[left]] == 0) {
            rightKind.erase(topping[left]);
        }
        
        // 왼쪽 하나 삽입
        leftCnt[topping[left]]++;
        leftKind.insert(topping[left]);
        
        if (leftKind.size() == rightKind.size()) {
            answer++;
        }
        left++;
    }
    
    return answer;
}
