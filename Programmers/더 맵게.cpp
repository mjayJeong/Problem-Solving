#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    // 1. 최소 힙 만들기
    for (int i = 0; i < scoville.size(); i++) {
        minHeap.push(scoville[i]);
    }
    
    // 2. 연산
    while (minHeap.top() < K) {
        if (minHeap.size() <= 1) {
            return -1;
        }

        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();
        
        int mixed = first + (second * 2);
        minHeap.push(mixed);
        answer++;
    }
    
    return answer;
}

