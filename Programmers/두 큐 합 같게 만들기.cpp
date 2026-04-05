#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    
    queue<int> q1, q2;
    long long sum1 = 0, sum2 = 0;
    
    for (int i = 0; i < queue1.size(); i++) {
        q1.push(queue1[i]);
        sum1 += queue1[i];
        
        q2.push(queue2[i]);
        sum2 += queue2[i];
    }
    
    int limit = queue1.size() * 3;

    while (sum1 != sum2 && answer <= limit) {
        if (sum1 > sum2) {
            int tmp = q1.front(); q1.pop();
            sum1 -= tmp;
            
            q2.push(tmp);
            sum2 += tmp;
        } else {
            int tmp = q2.front(); q2.pop();
            sum2 -= tmp;
            
            q1.push(tmp);
            sum1 += tmp;
        }
        
        answer++;
    }
    
    if (sum1 != sum2) return -1;
    return answer;
}
