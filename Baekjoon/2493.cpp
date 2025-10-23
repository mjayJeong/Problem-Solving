#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> answer(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    stack<pair<int, int>> st;
    
    for (int i = 0; i < n; i++) {
        // 현재 탑보다 낮은 탑들 제거
        while (!st.empty() && st.top().first <= v[i]) {
            st.pop();
        }

        // 스택이 비어있지 않으면 top이 신호 받음
        if (!st.empty()) {
            answer[i] = st.top().second;
        }

        // 현재 탑을 push
        st.push({v[i], i+1});
    }

    for (int x : answer) cout << x << ' ';

    return 0;
}
