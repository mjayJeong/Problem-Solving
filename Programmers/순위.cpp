#include <string>
#include <vector>

// 플로이드와샬 알고리즘 O(n^3)
// 1 -> 2 이기고, 2 -> 3 이기면, 1 -> 3 성립

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    bool vs[n][n];
    
    // vs배열 초기화
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++)
            vs[i][j] = false;
    }
    
    // 승자 true로 표시
    for (int i = 0; i < results.size(); i++) {
        vs[results[i][0] - 1][results[i][1] - 1] = true;
    }
    
    // 플로이드와샬 알고리즘
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (vs[j][i] == true && vs[i][k] == true) {
                    vs[j][k] = true;
                }
            }
        }
    }
    
    // 전체 개수가 n-1이면 순위 확정
    for (int i = 0; i < n; i++) {
        int tmp = 0;
        for (int j = 0; j < n; j++) {
            if (vs[i][j] == true) tmp++;
            if (vs[j][i] == true) tmp++;
        }
        if (tmp == n - 1) {
            answer++;
        }
    }

    return answer;
}
