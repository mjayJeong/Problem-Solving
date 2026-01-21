#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;


    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        if (max_heap.empty() || max_heap.size() == min_heap.size()) {
            max_heap.push(num);
        } else {
            min_heap.push(num);
        }

        // 순서가 깨졌을 때 스왑
        if (!min_heap.empty() && max_heap.top() > min_heap.top()) {
            int temp;
            temp = max_heap.top();
            max_heap.pop();
            max_heap.push(min_heap.top());
            min_heap.pop();
            min_heap.push(temp);
        }

        cout << max_heap.top() << '\n';
        
    }

    return 0;
}
