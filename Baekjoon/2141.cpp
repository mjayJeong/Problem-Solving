#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<pair<long long, long long>> town(N);
    long long total = 0;

    for (int i = 0; i < N; i++) {
        cin >> town[i].first >> town[i].second;
        total += town[i].second;
    }

    sort(town.begin(), town.end());   // 위치 순 정렬

    long long mid = (total + 1) / 2;  // 중앙값
    long long cnt = 0;
    for (int i = 0; i < N; i++) {
        cnt += town[i].second;
        if (cnt >= mid) {
            cout << town[i].first << "\n";
            break;
        } 
    }


    return 0;
}
