#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
vector<int> v;
int opCnt[4];
long long maxVal = LLONG_MIN, minVal = LLONG_MAX;

void dfs(int index, long long cur, int add, int sub, int mul, int div) {
    if (index == n) {
        maxVal = max(maxVal, cur);
        minVal = min(minVal, cur);
        return;
    }

    if (add > 0) dfs(index + 1, cur + v[index], add - 1, sub, mul, div);
    if (sub > 0) dfs(index + 1, cur - v[index], add, sub - 1, mul, div);
    if (mul > 0) dfs(index + 1, cur * v[index], add, sub, mul - 1, div);
    if (div > 0) {
        long long next;
        if (cur < 0) {
            next = - ( (-cur) / v[index]);
        } else {
            next = cur / v[index];
        }
        dfs(index + 1, next, add, sub, mul, div - 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> opCnt[i];
    }

    dfs(1, v[0], opCnt[0], opCnt[1], opCnt[2], opCnt[3]);

    cout << maxVal << '\n' << minVal << '\n';

    return 0; 
}
