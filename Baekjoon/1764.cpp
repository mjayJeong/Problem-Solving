#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    unordered_set<string> s;
    vector<string> answer;

    for (int i = 0; i < n; i++) {
        string person; 
        cin >> person;
        s.insert(person);
    }

    for (int i = 0; i < m; i++) {
        string finding;
        cin >> finding;
        if (s.find(finding) != s.end()) {
            answer.push_back(finding);
        }
    }
    sort(answer.begin(), answer.end());
    cout << answer.size() << '\n';
    for (int j = 0; j < answer.size(); j++) {
        cout << answer[j] << '\n';
    }

    return 0;
}
