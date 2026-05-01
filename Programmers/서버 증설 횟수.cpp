#include <string>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    int server_cnt = 0;                        // 현재 서버 개수 
    deque<pair<int, int>> server_time;         // 서버 증축 개수, 유지 시간
    
    for (int i = 0; i < players.size(); i++) {
        while (!server_time.empty() && server_time.front().second == i) {
            server_cnt -= server_time.front().first;
            server_time.pop_front();
        }
        
        int required = players[i] / m;
        
        if (required > server_cnt) {
            int need = required - server_cnt;
            
            server_cnt += need;
            server_time.push_back({need, i + k});
            answer += need;
        }
    }
    
    return answer;
}
