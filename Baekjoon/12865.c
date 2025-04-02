#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int weight[N];
    int value[N];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &weight[i], &value[i]);
    }

    int dp[N + 1][K + 1];

    // Initialize dp array
    for (int i = 0; i <= N; i++) {
        for (int w = 0; w <= K; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weight[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weight[i - 1]] + value[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("%d\n", dp[N][K]);
    return 0;
}
