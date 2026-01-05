#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Info {
    int id;
    int total;
    int submitCnt;
    int lastTime;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; 
    cin >> T;
    
    while (T--) {
        int n, k, t, m;
        cin >> n >> k >> t >> m;
        
        vector<vector<int>> score(n + 1, vector<int>(k + 1, 0));    // 팀당 문제 점수 저장
        vector<int> submitCnt(n + 1, 0);
        vector<int> lastTime(n + 1, 0);

        for (int time = 0; time < m; time++) {
            int i, j, s;
            cin >> i >> j >> s;

            score[i][j] = max(score[i][j], s);
            submitCnt[i]++;
            lastTime[i] = time;
        }

        vector<Info> teams;
        teams.reserve(n);

        for (int i = 1; i <= n; i++) {
            int total = 0;
            for (int j = 1; j <= k; j++) total += score[i][j];

            teams.push_back({i, total, submitCnt[i], lastTime[i]});
        }

        sort(teams.begin(), teams.end(), [](const Info& a, const Info& b) {
            if (a.total != b.total) return a.total > b.total;                   // 총점 내림차순
            if (a.submitCnt != b.submitCnt) return a.submitCnt < b.submitCnt;   // 제출횟수 오름차순
            return a.lastTime < b.lastTime;                                     // 마지막 제출시간 오름차순
        });

        for (int rank = 0; rank < n; rank++) {
            if (teams[rank].id == t) {
                cout << rank + 1 << '\n';
                break;
            }
        }
    }

    return 0;
}
