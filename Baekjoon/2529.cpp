#include <iostream>
#include <vector>
#include <string>

using namespace std;

int k;
vector<char> signArr;   // 부등호 저장
bool used[10];          // 숫자 사용 여부
string minStr = "";
string maxStr = "";

// 부등호 만족하는지 체크
bool ok(char sign, char a, char b) {
    if (sign == '<') return a < b;
    else return a > b;
}

void dfs(int idx, string cur) {
    if (idx == k + 1) {
        if (minStr == "") minStr = cur;
        maxStr = cur;
        return;
    }

    for (int num = 0; num <= 9; num++) {
        if (used[num]) continue;

        if (idx == 0 || ok(signArr[idx - 1], cur[idx - 1], num + '0')) {
            used[num] = true;
            dfs(idx + 1, cur + char(num + '0'));
            used[num] = false;
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> k;
    signArr.resize(k);

    for (int i = 0; i < k; i++) {
        cin >> signArr[i];
    }

    dfs(0, "");

    cout << maxStr << "\n";
    cout << minStr << "\n";

    return 0;
}
