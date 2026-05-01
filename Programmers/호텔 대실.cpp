#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 시간 변환 함수
int toMin(string s) {
    int h = stoi(s.substr(0, 2));   // 시간
    int m = stoi(s.substr(3, 2));   // 분
    return h * 60 + m;
}

int solution(vector<vector<string>> book_time) {
    sort(book_time.begin(), book_time.end());
    
    vector<int> rooms;       // 할당된 방 목록
    
    for (int i = 0; i < book_time.size(); i++) {
        int start = toMin(book_time[i][0]);
        int end = toMin(book_time[i][1]) + 10;
        
        bool assigned = false;
        
        for (int j = 0; j < rooms.size(); j++) {
            if (rooms[j] <= start) {
                rooms[j] = end;
                assigned = true;
                break;
            }
        }
        
        if (!assigned) {        // 못 채운 경우 -> 새로운 방 할당
            rooms.push_back(end);
        }
    }
    
    return rooms.size();
}

// 시작 시간 기준 정렬 
// 끝 시간보다 빨라서 못 넣으면 방 새로 만들고, vector에 넣기? 
