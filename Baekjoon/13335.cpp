#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, w, L;
    cin >> n >> w >> L;
    queue<int> order;
    for (int i = 0; i < n; i++) {
        int truck;
        cin >> truck;
        order.push(truck);
    }

    queue<int> bridge;
    for (int i = 0; i < w; i++) {
        bridge.push(0);
    }

    int time = 0, weight_sum = 0;

    while (!order.empty() || weight_sum > 0) {
        time++;

        // 시뮬레이션 시작 (맨 앞에 내리기)
        weight_sum -= bridge.front();
        bridge.pop();

        // 그 다음 트럭 올릴지 말지 결정
        if (!order.empty() && weight_sum + order.front() <= L) {
            weight_sum += order.front();
            bridge.push(order.front());
            order.pop();
        } else {
            bridge.push(0);
        }
    }

    cout << time;

    return 0;
}
