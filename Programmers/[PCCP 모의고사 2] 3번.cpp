#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> menu, vector<int> order, int k) {
    int answer = 0;
    
    queue<int> q;       // 아직 안 끝난 손님들 종료 시간
    int prev_end = 0;
    
    for (int i = 0; i < order.size(); i++) {
        int arrival = i * k;
        int cook_time = menu[order[i]];
        
        // 현재 손님 도착 전까지 끝난 손님 제거
        while (!q.empty() && q.front() <= arrival) {
            q.pop();
        }
        
        int start = max(arrival, prev_end);     // 실제 조리 시작
        int end = start + cook_time;            // 종료 시간
        
        q.push(end);
        prev_end = end;
        
        answer = max(answer, (int)q.size());         // 현재 큐 사이즈가 정답
    }
    
    return answer;
}
