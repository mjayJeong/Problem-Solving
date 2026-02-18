#include <iostream>
#include <vector>

using namespace std;

int N, M, k;
int parent[51];
vector<int> knowing;    // 이야기를 아는 사람들
vector<vector<int>> party(50);      // party 참여 명단

int Find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return x = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    parent[x] = y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> k;

    // parent 초기화
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    int x;
    
    // 이야기 아는 사람 입력
    while (k--) {
        cin >> x;
        knowing.push_back(x);
    }

    // 파티 명단 입력
    int p, num, prev;
    for (int i = 0; i < M; i++) {
        cin >> p;
        for (int j = 0; j < p; j++) {
            if (j >= 1) {       // 같은 파티 참여자들을 합침
                prev = num;
                cin >> num;
                Union(prev, num);
            } else {
                cin >> num;
            }
            party[i].push_back(num);
        }
    }

    int answer = M;
    for (auto& people : party) {
        bool flag = false;
        for (auto& person : people) {
            if (flag) {
                break;
            }
            for (auto& know : knowing) {
                if (Find(person) == Find(know)) {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) answer--;
    }

    cout << answer << '\n';
    
    return 0;
}
