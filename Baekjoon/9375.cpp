#include <iostream> 
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        unordered_map<string, int> um;
        for (int i = 0; i < n; i++) {
            string name, kind;
            cin >> name >> kind;
            um[kind]++;
        }

        long long answer = 1;

        for (auto &m : um) {
            answer *= (m.second + 1);
        }

        cout << answer - 1 << "\n";
    }

    return 0;
}
