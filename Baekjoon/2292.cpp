#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int answer = 1, sum = 1; 
    int i = 1; 
    while (sum < N) { 
        sum += (6 * i);
        i++;
        answer++;
    }
    cout << answer << '\n';

    return 0;
}
