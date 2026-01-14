#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int N;
int first[4] = {2, 3, 5, 7};    // 첫째 자리수
int odd[4] = {1, 3, 7, 9};   // 그 이후 홀수만

// 소수 판별 함수
bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

// DFS 돌려서 출력
void dfs(int start, int depth) {
    if (depth == N) {
        cout << start << '\n';
        return;
    }

    for (int o : odd) {
        int nxt = start * 10 + o;
        if (isPrime(nxt)) {
            dfs(nxt, depth + 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int num : first) {
        dfs(num, 1);
    }

    return 0;
}
