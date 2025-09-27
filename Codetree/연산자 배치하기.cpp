#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int op[3];
int arr[12];
int n;

int min_num = INT_MAX;
int max_num = INT_MIN;

void dfs(int index, int cur, int add, int sub, int mul)
{   
    // 계산 어디까지 했는지 
    if (index == n) {
        max_num = max(max_num, cur);
        min_num = min(min_num, cur);
        return;
    }
    // 백트래킹
    if (add > 0) dfs(index + 1, cur + arr[index], add - 1, sub, mul);
    if (sub > 0) dfs(index + 1, cur - arr[index], add, sub - 1, mul);
    if (mul > 0) dfs(index + 1, cur * arr[index], add, sub, mul - 1);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int j = 0; j < 3; j++) {
        cin >> op[j];
    }

    dfs(1, arr[0], op[0], op[1], op[2]);

    cout << min_num << ' ' << max_num;

    return 0;
}
