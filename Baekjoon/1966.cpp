#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        queue<pair<int,int>> q;     // (index, importance)
        priority_queue<int> pq;     // importance max heap

        for (int i = 0; i < N; i++) {
            int imp;
            cin >> imp;
            q.push({i, imp});
            pq.push(imp);
        }

        int printed = 0;

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            // 현재 문서가 가장 중요하면 인쇄
            if (cur.second == pq.top()) {
                pq.pop();
                printed++;

                if (cur.first == M) {
                    cout << printed << "\n";
                    break;
                }
            }
            // 아니면 다시 뒤로 보내기
            else {
                q.push(cur);
            }
        }
    }

    return 0;
}
