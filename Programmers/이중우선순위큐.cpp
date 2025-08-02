#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;
unordered_map<int, int> deleted;

void insert(int x) {
    maxHeap.push(x);
    minHeap.push(x);
}

template<typename T>
void cleanHeap(T& heap) {
    while (!heap.empty()) {
        int top = heap.top();
        if (deleted[top] > 0) {
            heap.pop();
            deleted[top]--;
        } else break;
    }
}

void deleteMax() {
    cleanHeap(maxHeap); 
    if (!maxHeap.empty()) {
        int top = maxHeap.top();
        maxHeap.pop();
        deleted[top]++;
    }
}

void deleteMin() {
    cleanHeap(minHeap);
    if (!minHeap.empty()) {
        int top = minHeap.top();
        minHeap.pop();
        deleted[top]++;
    }
}

int getMax() {
    return maxHeap.empty() ? -1 : maxHeap.top();
}

int getMin() {
    return minHeap.empty() ? -1 : minHeap.top();
}


vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    maxHeap = priority_queue<int>();
    minHeap = priority_queue<int, vector<int>, greater<int>>();
    deleted.clear();

    
    for (int i = 0; i < operations.size(); i++) {
        if (operations[i][0] == 'I') {
            string num = operations[i].substr(2);
            int n = stoi(num);
            
            insert(n);
        }
        else if (operations[i][0] == 'D') {
            if (operations[i][2] == '1') {
                deleteMax();
            } else {
                deleteMin();
            }
        }
    }

    int maxVal = getMax();
    int minVal = getMin();

    if (maxVal == -1 || minVal == -1) {
        answer.push_back(0);
        answer.push_back(0);
    } else {
        answer.push_back(maxVal);
        answer.push_back(minVal);
    }
    
    return answer;
}


