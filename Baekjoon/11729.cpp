#include <iostream>

using namespace std;

void hanoi(int n, int from, int to, int via) {
    if (n == 0) return; 
    hanoi(n-1, from, via, to);
    cout << from << ' ' << to << '\n';
    hanoi(n-1, via, to, from);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    // 2제곱 = 1 left shift 
    long long K = (1LL << N) - 1;
    cout << K << '\n';

    hanoi(N, 1, 3, 2);

    return 0;
}
