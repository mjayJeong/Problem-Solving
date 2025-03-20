#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    int now = 1; 
    stack<int> subBelt;  
    int i = 0; 

    while (now <= order.size()) {
        if (now == order[i]) {
            answer++;
            i++;  
            now++; 
        }
        else if (!subBelt.empty() && subBelt.top() == order[i]) {
            subBelt.pop();
            answer++;
            i++;  
        }
        
        else {
            subBelt.push(now);
            now++; 
        }
    }

    while (!subBelt.empty() && subBelt.top() == order[i]) {
        subBelt.pop();
        answer++;
        i++;  
    }

    return answer;
}
