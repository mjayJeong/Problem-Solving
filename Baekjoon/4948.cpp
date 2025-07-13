#include <iostream>

using namespace std;

bool isPrime(int n) {
	if (n < 2) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
    while (1) {
        int n;
        cin >> n;
        if (n == 0) break;

        int cnt = 0;
        for (int i = n + 1; i <= 2 * n; i++) {
            if (isPrime(i)) cnt++;
        }

        cout << cnt << '\n';
    }
    
    return 0;
}
