#include <string>

using namespace std;

string solution(string number, int k) {
    int cnt = 0; 
    int i = 0; 

    while (cnt < k && i < number.size() - 1) {
        if (number[i] < number[i + 1]) {
            number.erase(i, 1); 
            cnt++;
            if (i > 0) {
                i--;
            }
        } else {
            i++; 
        }
    }

    number.erase(number.size() - (k - cnt));

    return number;
}
