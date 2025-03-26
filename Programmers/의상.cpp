#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> clothCount;
    int answer = 1;
    
    for (int i = 0; i < clothes.size(); i++) {
        string name = clothes[i][0];
        string type = clothes[i][1];
        clothCount[type]++;
    }
    
    for (auto it : clothCount) {
        answer *= (it.second + 1);  
    }
    answer -= 1;
    
    return answer;
}
