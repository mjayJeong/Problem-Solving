#include <bits/stdc++.h>
using namespace std;

struct Box {
    int k;      // 번호
    int r, c;   // 좌상단 행, 열 (1-indexed)
    int h, w;   // 세로, 가로
};

int N, M;
vector<Box> boxes;              // 현재 존재하는 택배들
vector<vector<int>> grid;       // 격자: 0=빈칸, 그 외=택배 번호

// 격자를 boxes 상태로 다시 그리기
void rebuildGrid() {
    grid.assign(N + 1, vector<int>(N + 1, 0));
    for (auto &b : boxes) {
        for (int i = b.r; i < b.r + b.h; ++i)
            for (int j = b.c; j < b.c + b.w; ++j)
                grid[i][j] = b.k;
    }
}

// 직사각형 영역이 비어있는지
bool areaEmpty(int r, int c, int h, int w) {
    if (r < 1 || c < 1 || r + h - 1 > N || c + w - 1 > N) return false;
    for (int i = r; i < r + h; ++i)
        for (int j = c; j < c + w; ++j)
            if (grid[i][j] != 0) return false;
    return true;
}

// 한 박스를 위에서 c열에 떨어뜨려 최종 r을 결정해 boxes에 추가
void dropBox(int k, int h, int w, int c) {
    // 일단 현재 격자 반영
    rebuildGrid();

    // r을 위에서부터 찾기: 먼저 빈 영역을 찾고, 그 다음 아래로 더 내려갈 수 있을 때까지 내림
    int r = 1;
    while (!areaEmpty(r, c, h, w)) r++;                    // 처음 비는 r 찾기
    while (r + h <= N && areaEmpty(r + 1, c, h, w)) r++;   // 더 내려갈 수 있으면 최대로

    boxes.push_back({k, r, c, h, w});
    rebuildGrid();
}

// 중력 적용: 더 내려갈 수 없는 상태가 될 때까지 반복
void applyGravity() {
    bool moved = true;
    while (moved) {
        moved = false;
        // 현재 그리드 기준으로 각 박스를 아래로 한 칸 이동 가능하면 이동
        // 이동/겹침을 피하려고, 내려갈 때는 아래에 있는 박스부터 처리하도록
        // 박스들을 바닥 기준(아래쪽) 순으로 정렬해 주면 안정적임
        sort(boxes.begin(), boxes.end(),
             [](const Box& a, const Box& b) {
                 return (a.r + a.h) > (b.r + b.h); // 바닥이 더 아래인 순
             });

        rebuildGrid();
        for (auto &b : boxes) {
            if (b.r + b.h - 1 == N) continue; // 이미 바닥
            bool can = true;
            for (int j = b.c; j < b.c + b.w; ++j) {
                if (grid[b.r + b.h][j] != 0) { // 바로 아래 한 줄 체크
                    can = false; break;
                }
            }
            if (can) {
                // 자기 자리 비우고 한 칸 아래로
                for (int i = b.r; i < b.r + b.h; ++i)
                    for (int j = b.c; j < b.c + b.w; ++j)
                        grid[i][j] = 0;
                b.r++;
                for (int i = b.r; i < b.r + b.h; ++i)
                    for (int j = b.c; j < b.c + b.w; ++j)
                        grid[i][j] = b.k;
                moved = true;
            }
        }
    }
}

// 왼쪽으로 나갈 수 있는지: 박스가 차지하는 각 행에서 자신의 왼쪽이 전부 비어있어야 함
bool canLeaveLeft(const Box &b) {
    for (int i = b.r; i < b.r + b.h; ++i)
        for (int j = 1; j < b.c; ++j)
            if (grid[i][j] != 0) return false;
    return true;
}

// 오른쪽으로 나갈 수 있는지: 박스가 차지하는 각 행에서 자신의 오른쪽이 전부 비어있어야 함
bool canLeaveRight(const Box &b) {
    for (int i = b.r; i < b.r + b.h; ++i)
        for (int j = b.c + b.w; j <= N; ++j)
            if (grid[i][j] != 0) return false;
    return true;
}

// 해당 방향으로 뺄 수 있는 후보 중 번호가 가장 작은 박스를 하나 제거
// dir = -1(왼쪽), +1(오른쪽). 성공하면 제거된 번호 반환, 없으면 -1.
int unloadOne(int dir) {
    rebuildGrid();
    int pickIdx = -1;
    int bestK = INT_MAX;

    for (int i = 0; i < (int)boxes.size(); ++i) {
        const auto &b = boxes[i];
        bool ok = (dir == -1) ? canLeaveLeft(b) : canLeaveRight(b);
        if (ok && b.k < bestK) {
            bestK = b.k;
            pickIdx = i;
        }
    }
    if (pickIdx == -1) return -1;

    // 제거
    int removedK = boxes[pickIdx].k;
    // 그리드에서 지우고 벡터에서도 제거
    for (int i = boxes[pickIdx].r; i < boxes[pickIdx].r + boxes[pickIdx].h; ++i)
        for (int j = boxes[pickIdx].c; j < boxes[pickIdx].c + boxes[pickIdx].w; ++j)
            grid[i][j] = 0;
    boxes.erase(boxes.begin() + pickIdx);

    // 중력으로 재정렬
    applyGravity();
    return removedK;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    grid.assign(N + 1, vector<int>(N + 1, 0));
    boxes.clear();

    // 1) 투입(떨어뜨리기)
    for (int i = 0; i < M; ++i) {
        int k, h, w, c;
        cin >> k >> h >> w >> c;
        dropBox(k, h, w, c);
    }

    // 2) 하차: 왼쪽, 오른쪽을 번갈아가며 반복
    vector<int> answer;
    int dir = -1; // -1: 왼쪽, +1: 오른쪽
    while (!boxes.empty()) {
        int out = unloadOne(dir);
        // 해당 방향으로 못 빼면 반대 방향 시도
        if (out == -1) {
            dir *= -1;
            out = unloadOne(dir);
            // 이 경우엔 반드시 하나는 빠진다고 문제 특성상 가정
        }
        answer.push_back(out);
        dir *= -1; // 다음에는 반대 방향부터 시도
    }

    for (int k : answer) cout << k << '\n';
    return 0;
}
