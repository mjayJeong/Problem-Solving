#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;

    for (int i = 0; i < n; i++) {
        long long num; 
        cin >> num;
        minHeap.push(num);
    }

    for (int j = 0; j < m; j++) {
        long long x = minHeap.top();
        minHeap.pop();
        long long y = minHeap.top();
        minHeap.pop();
        
        long long add = x + y;
        minHeap.push(add);
        minHeap.push(add);
    }
    
    long long answer = 0;
    while (!minHeap.empty()) {
        answer += minHeap.top();
        minHeap.pop();
    }
    cout << answer;

    return 0;
}
