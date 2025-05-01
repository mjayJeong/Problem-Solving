#include <stdio.h>


int dp[1001];

int solve(int x) {
    if (x == 0) return 1;
    if (x == 1) return 0;
    if (x == 2) return 3;
    if (dp[x] != 0) return dp[x];
    int result = 3 * solve(x-2);
    for (int i = 3; i <= x; i++)
    {
        if (i % 2 == 0) {
            result += 2 * solve(x-i);
        }
    }
    return dp[x] = result;
}

int main()
{
    int x;
    scanf("%d", &x);
    printf("%d", solve(x));

    return 0;
}
