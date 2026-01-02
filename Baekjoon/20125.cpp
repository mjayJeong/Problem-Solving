#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
vector<vector<char>> grid;
pair<int, int> heart = {0, 0};                // 심장 위치

void find_heart() {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid.size(); j++) {
            if (grid[i][j] == '*') {
                heart.first = i + 1;
                heart.second = j;
                return;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    grid.resize(N, vector<char>(N));
    cin.ignore();

    for (int i = 0; i < N; i++) {
        string line;
        getline(cin, line);

        for (int j = 0; j < line.size(); j++) {
            grid[i][j] = line[j];
        }
    }

    find_heart();

    int left_hand = -1, right_hand = -1, waist = -1, left_leg = 0, right_leg = 0;
    pair<int, int> waist_loc;       // 허리 끝 좌표 저장
    
    // 왼팔 구하기 
    for (int i = heart.second; i >= 0; i--) {
        if (grid[heart.first][i] == '*') left_hand++; 
    }    
    
    // 오른팔 구하기
    for (int i = heart.second; i < N; i++) {
        if (grid[heart.first][i] == '*') right_hand++; 
    }

    // 허리 구하기 
    for (int i = heart.first; i < N; i++) {
        if (grid[i][heart.second] == '*') {
            waist++;
        }
        else {
            waist_loc = {i-1, heart.second};
            break;
        }
    }

    // 왼다리 구하기
    for (int i = waist_loc.first + 1; i < N; i++) {
        if (grid[i][waist_loc.second-1] == '*') left_leg++;
        else break; 
    }
    // 오른다리 구하기
    for (int i = waist_loc.first + 1; i < N; i++) {
        if (grid[i][waist_loc.second+1] == '*') right_leg++;
        else break; 
    }

    cout << heart.first + 1 << ' ' << heart.second + 1 << '\n';
    cout << left_hand << ' ' << right_hand << ' ' << waist << ' ' << left_leg << ' ' << right_leg; 

    return 0;
}
