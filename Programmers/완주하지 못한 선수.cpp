#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> s;
    
    for (const auto& name : participant) {
        s[name]++;
    }
    
    for (const auto& name : completion) {
        s[name]--;
    }    
    
    for (const auto& [name, c] : s) {
        if (c > 0) {
            return name;
        }
    }
    return "";
}
