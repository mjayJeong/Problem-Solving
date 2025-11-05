#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<string> results;

// 수식 평가 함수
int calc(const string& expr) {
    string temp;
    vector<char> op;
    vector<int> num;

    // expr 문자열 읽어서 파싱
    for (int i = 0; i < expr.size(); i++) {
        if (expr[i] == '+' || expr[i] == '-') {
            num.push_back(stoi(temp));
            op.push_back(expr[i]);
            temp.clear();
        } else if (expr[i] != ' ') {
            temp += expr[i];
        }
    }
    num.push_back(stoi(temp));

    // 담아 놓은 수식들 기반 계산 
    int result = num[0];
    for (int i = 0; i < op.size(); i++) {
        if (op[i] == '+') result += num[i+1];
        else result -= num[i+1];
    }
    return result;
}

void backtracking(int idx, string expr) {
    if (idx == N) {
        if (calc(expr) == 0) {
            results.push_back(expr);
        }
        return;
    }
    // 다음 숫자 붙이기
    backtracking(idx + 1, expr + ' ' + to_string(idx + 1));
    backtracking(idx + 1, expr + '+' + to_string(idx + 1));
    backtracking(idx + 1, expr + '-' + to_string(idx + 1));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N; 
        results.clear();

        backtracking(1, "1");   // 시작은 1부터 항상
        
        for (auto& s : results) {
            cout << s << '\n';
        }
        cout << '\n';
    }

    return 0;
}
