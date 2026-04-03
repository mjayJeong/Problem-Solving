#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int> solution(string s) {
    vector<vector<int>> groups;
    vector<int> current;
    int num = 0;
    bool inNumber = false;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        if (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
            inNumber = true;
        } else {
            if (inNumber) {
                current.push_back(num);
                num = 0;
                inNumber = false;
            }

            if (c == '}') {
                if (!current.empty()) {
                    groups.push_back(current);
                    current.clear();
                }
            }
        }
    }

    sort(groups.begin(), groups.end(), [](const vector<int>& a, const vector<int>& b) {
        return a.size() < b.size();
    });

    vector<int> answer;
    unordered_set<int> seen;

    for (auto& group : groups) {
        for (int x : group) {
            if (seen.find(x) == seen.end()) {
                seen.insert(x);
                answer.push_back(x);
            }
        }
    }

    return answer;
}
