#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> days;

    for (int i = 0; i < progresses.size(); i++) {
        int remaining = 100 - progresses[i];
        int required_days = (remaining + speeds[i] - 1) / speeds[i];
        days.push(required_days);
    }

    while (!days.empty()) {
        int count = 1; 
        int first = days.front();
        days.pop();

        while (!days.empty() && days.front() <= first) {
            count++;
            days.pop();
        }

        answer.push_back(count);
    }

    return answer;
}
