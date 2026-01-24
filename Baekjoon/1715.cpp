#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; i++) {
        int num; 
        cin >> num;
        pq.push(num);
    }

    int answer = 0; 
    while (pq.size() > 1) {
        int sum = pq.top();
        pq.pop();
        sum += pq.top();
        pq.pop();

        pq.push(sum);
        answer += sum;
    }

    cout << answer << '\n';

    return 0; 
}
