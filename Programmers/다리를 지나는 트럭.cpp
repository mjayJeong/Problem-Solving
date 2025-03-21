#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    int total_weight = 0;
    queue<int> bridge;
    
    for (int i = 0; i < bridge_length; i++) {
        bridge.push(0);
    }
    
    int index;
    
    while (index < truck_weights.size() || total_weight > 0) {
        time++;
        
        total_weight -= bridge.front();
        bridge.pop();
        
        if (index < truck_weights.size()) {
            if (total_weight + truck_weights[index] <= weight) {
                bridge.push(truck_weights[index]);
                total_weight += truck_weights[index];
                index++;
            } else {
                bridge.push(0);
            }
        }
    }
    
    return time;
}
