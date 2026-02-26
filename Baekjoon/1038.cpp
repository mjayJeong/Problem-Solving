#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long N;
vector<long long> answer;

void backtracking(long long start, int lastDigit) 
{
    answer.push_back(start);
    for (int d = 0; d < lastDigit; d++) {
        backtracking(start * 10 + d, d);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i <= 9; i++) {
        backtracking(i, i);
    }
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());   // 중복 제거

    if (N >= (long long)answer.size()) cout << -1 << "\n";
    else cout << answer[N] << '\n';

    return 0;
}
