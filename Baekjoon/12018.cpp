#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> answer;     // 각 과목당 마일리지 필요량 저장
    
    for (int i = 0; i < n; i++) {
        int p, l;
        cin >> p >> l;
        vector<int> people(p);
        for (int j = 0; j < p; j++) {
            cin >> people[j];
        }
        sort(people.begin(), people.end(), greater<>());

        if (p < l) answer.push_back(1);
        else answer.push_back(people[l-1]);
    }

    sort(answer.begin(), answer.end());

    // 개수 카운팅
    int used = 0;
    int result = 0;

    for (int i = 0; i < n; i++) {
        if (used + answer[i] > m) break;
        used += answer[i];
        result++;
    }

    cout << result << "\n";

    return 0;
}
