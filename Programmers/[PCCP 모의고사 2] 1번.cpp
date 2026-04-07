#include <string>
#include <vector>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

vector<int> solution(string command) {
    vector<int> answer;
    
    int cur = 0;
    pair<int, int> loc = {0, 0};
    
    for (int i = 0; i < command.size(); i++) {
        if (command[i] == 'G') {
            loc.first += dx[cur];
            loc.second += dy[cur];
        } else if (command[i] == 'B') {
            loc.first += dx[(cur + 2) % 4];
            loc.second += dy[(cur + 2) % 4];
        } else if (command[i] == 'R') {
            cur = (cur + 1) % 4;
        } else if (command[i] == 'L') {
            cur = (cur + 3) % 4;
        }
    }
    
    // 행, 열 +/- 부호 반대로 넣기 
    answer.push_back(loc.second);
    answer.push_back(-loc.first);
    
    return answer;
}
