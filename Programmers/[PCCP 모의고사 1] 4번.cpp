#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
    int score;
    int callTime;
    int runTime;
};

struct cmp {
    bool operator() (const Node& a, const Node& b) {
        if (a.score != b.score) return a.score > b.score;       // 점수 낮을수록 우선
        return a.callTime > b.callTime;                         // 호출 시간 빠를수록 우선
    }
};

vector<long long> solution(vector<vector<int>> program) {
    vector<long long> answer(11, 0);
    
    sort(program.begin(), program.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];     // 호출 시간 기준 정렬
    });
    
    priority_queue<Node, vector<Node>, cmp> pq;
    
    long long curTime = 0; 
    int idx = 0;
    int n = program.size();
    
    while (idx < n || !pq.empty()) {
        // 현재 호출시간까지 호출된 프로그램 모두 삽입
        while (idx < n && program[idx][1] <= curTime) {
            pq.push({program[idx][0], program[idx][1], program[idx][2]});
            idx++;
        }
        
        // 실행 프로그램 없으면 다음 호출 시각으로 점프
        if (pq.empty()) {
            curTime = program[idx][1];
            continue;
        }
        
        // 우선 순위 가장 높은 프로그램 실행
        Node now = pq.top();
        pq.pop();
        
        long long waitTime = curTime - now.callTime;
        answer[now.score] += waitTime;
        
        curTime += now.runTime;
    }
    answer[0] = curTime;
    
    return answer;
}
