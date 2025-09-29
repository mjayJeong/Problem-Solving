#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<pair<int, int>> homes;       // 집 좌표 저장
vector<pair<int, int>> chicken;     // 치킨집 좌표 저장
int answer = 1e9;

void calculate_min(vector<int>& v)
{
    int total = 0; 
    for (auto& h : homes) {
        int dist = 1e9;
        for (int idx : v) {
            auto c = chicken[idx];
            dist = min(dist, abs(h.first - c.first) + abs(h.second - c.second));
        }
        total += dist;
    }
    answer = min(answer, total);
}


void dfs(int num, vector<int>& v)
{   
    if (v.size() == m) {
        calculate_min(v);
        return;
    }

    // 백트래킹
    for (int i = num; i < chicken.size(); i++) {
        v.push_back(i);
        dfs(i+1, v);
        v.pop_back();
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x == 1) homes.push_back({i, j});
            else if (x == 2) chicken.push_back({i, j});
        }
    }
    vector<int> selected;  // 조합으로 선택된 좌표 저장
    dfs(0, selected);
    cout << answer;

    return 0;
}


// 처음에 입력받을 때 치킨집, 집 좌표 따로 저장 
// 치킨집 좌표 중에서 조합으로 뽑기 (백트래킹)
// 뽑은 좌표들 사이에서 최소 거리 계산해서 모든 집에 대해서 다 더함
// 조합 바꿔가면서 최소값 갱신
