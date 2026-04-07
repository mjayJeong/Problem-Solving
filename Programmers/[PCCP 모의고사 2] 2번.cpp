#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> ability, int number) {
    int answer = 0;
    
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < ability.size(); i++) {
        pq.push(ability[i]);
    }
    
    for (int i = 0; i < number; i++) {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        
        long long train = a + b;
        
        pq.push(train);
        pq.push(train);
    }
    
    while (!pq.empty()) {
        answer += pq.top();
        pq.pop();
    }
    
    return answer;
}
