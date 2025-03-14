#include <string>
#include <vector>

using namespace std;

int answer = 0;

void get_target(vector<int> numbers, int target, int sum, int index) {
    if (index == numbers.size()) {
        if (sum == target) {
            answer++;
        }
        return;
    }
    get_target(numbers, target, sum + numbers[index], index+1);
    get_target(numbers, target, sum - numbers[index], index+1);
}


int solution(vector<int> numbers, int target) {
    get_target(numbers, target, 0, 0);
    
    return answer;
}
