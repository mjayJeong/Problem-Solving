#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    // 변수 선언
    int answer = 0;
    int size = priorities.size();
    queue<int> q;
    
    // 1. 큐에 담기
    for (int i = 0; i < size; i++) {
        q.push(i);
    }
    
    while (1) {
        int max_value = *max_element(priorities.begin(), priorities.end());
        
        int head = q.front();
        // 종료조건
        if (head == location && priorities[head] == max_value) {
            answer++;
            break;
        }
        // 그냥 최고 값일때 제거
        if (priorities[head] == max_value) {
            q.pop();
            priorities[head] = -100;
            answer++;
        }  // 최고 값 아닌 경우 
        else {
            q.pop();
            q.push(head);
        }
    }
    
    
    return answer;
}
