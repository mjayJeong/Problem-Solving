#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b) {
    if (a[1] < b[1]) return true;
    else if (a[1] == b[1]) return a[0] < b[0];
    return false;
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), cmp);
    
    int cur = routes[0][1];     // 현재 위치 
    answer++;
    
    for (int i = 1; i < routes.size(); i++) {
        if (cur >= routes[i][0]) {
            continue;
        } else {
            answer++;
            cur = routes[i][1];
        }
    }
    
    return answer;
}
