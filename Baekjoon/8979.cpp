#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Info {
    int id;
    int gold;
    int silver;
    int bronze;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    vector<Info> teams;

    for (int i = 0; i < N; i++) {
        int c, g, s, b;
        cin >> c >> g >> s >> b;

        teams.push_back({c, g, s, b});
    }

    sort(teams.begin(), teams.end(), [](const Info& a, const Info& b) {
        if (a.gold != b.gold) return a.gold > b.gold;
        if (a.silver != b.silver) return a.silver > b.silver;
        return a.bronze > b.bronze; 
    });

    int rank = 1;   // 현재 등수

    for (int i = 0; i < N; i++) {

        // 이전 나라와 메달이 다르면 등수 갱신
        if (i > 0) {
            if (teams[i].gold != teams[i-1].gold || teams[i].silver != teams[i-1].silver || teams[i-1].bronze != teams[i-1].bronze) {
                rank = i + 1;
            }
        }

        if (teams[i].id == K) {
            cout << rank << '\n';
            break;
        }
    }

    return 0;
}
