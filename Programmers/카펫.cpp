#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int key = 0, value = 0;
    
    for (int i = yellow; i > 0; i--) {
        if (yellow % i == 0) {
            key = i; 
            value = yellow / key;
        }
        if (((key + value)*2 + 4) == brown) break;
    }
    answer.push_back(key+2);
    answer.push_back(value+2);
    
    return answer;
}

