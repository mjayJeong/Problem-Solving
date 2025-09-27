#include <bits/stdc++.h>
using namespace std;

bool coverable(const vector<long long>& a, int r, long long T) {
    int n = (int)a.size(), i = 0, used = 0;
    while (i < n && used < r) {
        long long reach = a[i] + T;
        ++used;
        while (i < n && a[i] <= reach) ++i;
    }
    return i == n;
}

long long min_time(const vector<long long>& a, int r) {
    if (a.empty()) return 0;
    long long lo = 0, hi = a.back() - a.front();
    while (lo < hi) {
        long long mid = (lo + hi) / 2;
        if (coverable(a, r, mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    vector<long long> homes; 

    while (Q--) {
        int op; 
        cin >> op;

        switch (op) {
        case 100: { // 마을 건설: homes를 새로 구성
            int N; 
            cin >> N;
            homes.clear();
            homes.reserve(N);
            for (int i = 0; i < N; ++i) {
                long long x; 
                cin >> x;
                homes.push_back(x);
            }
            sort(homes.begin(), homes.end());
            break;
        }
        case 200: { // 개미집 건설
            long long p; 
            cin >> p;
            homes.push_back(p);
            sort(homes.begin(), homes.end());
            break;
        }
        case 300: { // 개미집 철거 (1-index)
            int idx; 
            cin >> idx;
            if (1 <= idx && idx <= (int)homes.size())
                homes.erase(homes.begin() + (idx - 1));
            // else: 무시(또는 에러 처리)
            break;
        }
        case 400: { // 개미집 정찰
            int r; 
            cin >> r;
            cout << min_time(homes, r) << '\n';
            break;
        }
        default:
            break;
        }
    }
    return 0;
}
