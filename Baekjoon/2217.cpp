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
    vector<int> rope(N);

    for (int i = 0; i < N; i++) {
        cin >> rope[i];
    }
    sort(rope.begin(), rope.end(), greater<int>());
    
    int answer = 0;
    for (int i = 0; i < N; i++) {
        answer = max(answer, rope[i] * (i + 1));
    }

    cout << answer << "\n";

    return 0;
}
