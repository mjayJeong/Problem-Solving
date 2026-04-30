#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        long long N;
        cin >> N;

        long long answer = 0;

        while (N != 2) {
            long long r = sqrt(N);

            if (r * r == N) {
                N = r;
                answer++;
            } else {
                long long next = r + 1;
                long long nextSquare = next * next;

                answer += nextSquare - N;
                N = nextSquare;
            }
        }

        cout << "#" << tc << " " << answer << '\n';
    }

    return 0;
}
