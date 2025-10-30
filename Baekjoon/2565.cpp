#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[i] = {a, b};  
    }
    sort(v.begin(), v.end());

    vector<int> dp(n, 1);
    int answer = 0;                     // 최대 LIS
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[i].second > v[j].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        answer = max(answer, dp[i]);
    }

    cout << (n - answer) << '\n';       // 제거해야 하는 개수니깐 빼기

    return 0;
}


// 첫번째 값 기준으로 정렬
// 두번째 값 기준으로 LIS 길이 구하기 
