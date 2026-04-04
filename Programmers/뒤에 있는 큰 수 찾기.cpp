#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    stack<int> s;
    vector<int> answer(numbers.size(), -1);
    
    for (int i = numbers.size() - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= numbers[i]) {
            s.pop();
        }
        
        if (!s.empty()) {
            answer[i] = s.top();
        }
        
        s.push(numbers[i]);
    }
    
    return answer;
}
