#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int K;
    cin >> K;
    vector<pair<int, int>> v(6);
    int max_width = 0, max_height = 0;     // 가로, 세로 최대 길이
    int w_idx = 0, h_idx = 0;
    for (int i = 0; i < 6; i++) {
        cin >> v[i].first >> v[i].second;
        
        if ((v[i].first == 1 || v[i].first == 2) && max_width < v[i].second) {
            max_width = v[i].second;
            w_idx = i;
        }
        if ((v[i].first == 3 || v[i].first == 4) && max_height < v[i].second) {
            max_height = v[i].second;
            h_idx = i;
        }
    }

    int small_height = v[(w_idx + 3) % 6].second;   // 최대 가로의 3칸뒤 = 작은 세로
    int small_width = v[(h_idx + 3) % 6].second;    // 최대 세로의 3칸뒤 = 작은 가로 

    int answer = ((max_width * max_height) - (small_height * small_width)) * K; 

    cout << answer << "\n";

    return 0;
}
