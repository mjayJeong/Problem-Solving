#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    deque<int> dq;
    vector<int> seq(n);
    vector<int> answer; 

    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }

    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }

    while (!dq.empty()) {
        int index = dq.front();           
        answer.push_back(index);     
        dq.pop_front();           

        if (dq.empty()) break;      

        int move = seq[index - 1];   

        if (move > 0) {
            for (int i = 0; i < move - 1; i++) { 
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } else {
            for (int i = 0; i < abs(move); i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }

    return 0;
}
