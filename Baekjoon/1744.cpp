#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> plus, minus, zero, one;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (num > 1) plus.push_back(num);
        else if (num < 0) minus.push_back(num);
        else if (num == 0) zero.push_back(num);
        else if (num == 1) one.push_back(num);
    }

    sort(plus.begin(), plus.end(), greater<int>());
    sort(minus.begin(), minus.end());

    long long answer = 0;

    for (int i = 0; i + 1 < plus.size(); i += 2) {
        answer += 1LL * plus[i] * plus[i+1];
    }
    if (plus.size() % 2 != 0) answer += plus.back();

    for (int i = 0; i + 1 < minus.size(); i += 2) {
        answer += 1LL * minus[i] * minus[i+1];
    }

    // 남는 음수는 0 있으면 0이랑 합쳐서 없애기 
    if (minus.size() % 2 != 0) { 
        if (zero.empty()) { 
            answer += minus.back();
        } 
    } 
    
    answer += one.size();
    
    cout << answer << "\n";

    return 0;
}
