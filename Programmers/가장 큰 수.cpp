#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    
    vector<string> strNumbers;

    for (int num : numbers) {
        strNumbers.push_back(to_string(num)); 
    }
    
    sort(strNumbers.begin(), strNumbers.end(), [](string &a, string &b) {
        return a + b > b + a;
    });
    
    string answer;
    for (string &s : strNumbers) {
        answer += s;
    }

    if (answer[0] == '0') return "0";
    
    return answer;
}
