#include <string>
#include <vector>
#include <cmath>

using namespace std;

int get_distance(pair<int, int> a, pair<int, int> b) 
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}


// 현재 거리 바탕으로 입력 손가락 확정
char get_hand(pair<int, int> l, pair<int, int> r, pair<int, int> target, string hand) 
{
    int left_dist = get_distance(l, target);
    int right_dist = get_distance(r, target);
    
    if (left_dist > right_dist) {
        return 'R';
    } else if (left_dist == right_dist) {
        if (hand == "left") return 'L';
        else return 'R';
    } else {
        return 'L';
    }
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    // 숫자에 따른 현재 위치 좌표 
    pair<int,int> pos[10] = {
        {3,1}, // 0
        {0,0}, {0,1}, {0,2},
        {1,0}, {1,1}, {1,2},
        {2,0}, {2,1}, {2,2}
    };
    
    pair<int, int> left = {3, 0};       // *
    pair<int, int> right = {3, 2};      // #
    
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer.push_back('L');
            left = pos[numbers[i]];
        } else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer.push_back('R');
            right = pos[numbers[i]];
        } else if (numbers[i] == 2 || numbers[i] == 5 || numbers[i] == 8 || numbers[i] == 0) {
            char w = get_hand(left, right, pos[numbers[i]], hand);
            answer.push_back(w);
            
            if (w == 'L') left = pos[numbers[i]];
            else right = pos[numbers[i]];
        }
    }
    
    return answer;
}
