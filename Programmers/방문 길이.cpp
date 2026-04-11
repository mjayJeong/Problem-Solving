#include <string>
#include <set>
#include <tuple>

using namespace std;

int solution(string dirs) {
    int answer = 0;
    
    int x = 5, y = 5;
    set<tuple<int, int, int, int>> visited;     // 양방향 모두 저장
    
    for (char dir : dirs) {
        int nx = x, ny = y;
        
        if (dir == 'U') nx--;
        else if (dir == 'D') nx++;
        else if (dir == 'L') ny--;
        else if (dir == 'R') ny++;
        
        if (nx < 0 || nx > 10 || ny < 0 || ny > 10) continue;
        
        // visited 배열에서 못 찾으면
        if (visited.find({x, y, nx, ny}) == visited.end()) {
            answer++;
            visited.insert({x, y, nx, ny});
            visited.insert({nx, ny, x, y});
        }
        
        x = nx;
        y = ny;
    }
    
    return answer;
}
