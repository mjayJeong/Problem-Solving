#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long K;
    cin >> K;

    long long S = 1;
    while (S < K) {
        S <<= 1;
    }

    long long cuts = 0;
    long long need = K;
    long long piece = S;
    while (need > 0) {
        if (piece <= need) {
            need -= piece;
        } else {
            piece >>= 1;
            cuts++;
        }
    }

    cout << S << ' ' << cuts;

    return 0;
}
