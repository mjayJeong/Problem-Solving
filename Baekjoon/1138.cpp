#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> people(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> people[i];
    }

    vector<int> answer;      // 정답 저장

    for (int i = N; i >= 1; i--) {
        answer.insert(answer.begin() + people[i], i);
    }

    for (int x : answer) {
        cout << x << ' ';
    }

    return 0;
}
