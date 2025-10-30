#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_map<string, bool> u;
    
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        string state;
        cin >> state;
        if (state == "enter") {
            u[name] = true;
        } else if (state == "leave") {
            u[name] = false;
        }
    }
    vector<string> answer;

    for (const auto& i : u) {
        if (i.second) {
            answer.push_back(i.first);
        }
    }
    sort(answer.rbegin(), answer.rend());
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << '\n';
    }

    return 0;
}
