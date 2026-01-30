#include <bits/stdc++.h>

using namespace std;

int main()
{
    int p, m;
    cin >> p >> m;
    vector<pair<int, string>> info;
    info.reserve(p);
    vector<vector<pair<int, string>>> room;
    room.reserve(p);

    for (int i = 0; i < p; i++) {
        int l;
        string n;
        cin >> l >> n;
        info.push_back({l, n});
    }
    vector<int> standard; 
    standard.reserve(p);    // 각 방의 기준치 저장

    // 커다란 2차원 배열 만들고 넣기
    for (int i = 0; i < p; i++) {
        int lv = info[i].first;
        string name = info[i].second;

        bool placed = false;

        // 기존 방들 중 들어갈 수 있는 첫 방 찾기
        for (int j = 0; j < (int)standard.size(); j++) {
            if (standard[j] - 10 <= lv && lv <= standard[j] + 10 && (int)room[j].size() < m) {
                room[j].push_back({lv, name});
                placed = true;
                break;
            }
        }

        // 못 넣으면 새 방 생성
        if (!placed) {
            room.push_back({});
            room.back().push_back({lv, name});
            standard.push_back(lv);
        }
    }

    for (int i = 0; i < (int)room.size(); i++) {
        // 닉네임 기준 오름차순 정렬 
        sort(room[i].begin(), room[i].end(),
             [](const pair<int, string>& a, const pair<int, string>& b) {
                 return a.second < b.second;
             });

        if ((int)room[i].size() == m) cout << "Started!\n";
        else cout << "Waiting!\n";

        for (auto &pr : room[i]) {
            cout << pr.first << " " << pr.second << "\n";
        }
    }

    return 0;
}
