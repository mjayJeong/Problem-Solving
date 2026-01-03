#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    string word;
    vector<char> table(N);
    cin >> word;

    for (int i = 0; i < word.size(); i++) {
        table[i] = word[i];
    }

    int answer = 0;
    for (int i = 0; i < N; i++) {
        if (table[i] == 'P') {
            
            // 배열 범위 초과 방지
            int left = max(0, i - K);
            int right = min(N - 1, i + K);

            for (int j = left; j <= right; j++) {
                if (table[j] == 'H') {
                    table[j] = '.';
                    answer++;
                    break;
                }
            }
        }
    }

    cout << answer << '\n';

    return 0;
}
