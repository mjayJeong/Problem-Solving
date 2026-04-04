#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<int> xCnt(10, 0), yCnt(10, 0);
    
    for (int i = 0; i < X.size(); i++) {
        int num = X[i] - '0';
        xCnt[num]++;
    }
    for (int i = 0; i < Y.size(); i++) {
        int num = Y[i] - '0';
        yCnt[num]++;
    }
    
    for (int i = yCnt.size() - 1; i >= 0; i--) {
        int cnt = min(xCnt[i], yCnt[i]);
        for (int j = 0; j < cnt; j++) {
            answer += to_string(i);
        }
    }
    if (answer == "") return "-1";
    if (answer[0] == '0') return "0";
    
    return answer;
}
