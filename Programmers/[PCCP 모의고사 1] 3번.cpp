#include <string>
#include <vector>

using namespace std;

string getGene(int n, int p) {
    if (n == 1) return "Rr";
    
    int blockSize = 1;
    for (int i = 0; i < n - 2; i++) {
        blockSize *= 4;
    }
    
    int group = (p - 1) / blockSize;        // 4등분 해서 첫 번째는 Rr, 마지막은 rr
    
    if (group == 0) return "RR";
    if (group == 3) return "rr";
    
    // 중간은 재귀적으로 더 추적
    return getGene(n - 1, (p - 1) % blockSize + 1);
}

vector<string> solution(vector<vector<int>> queries) {
    vector<string> answer;
    
    for (auto& q : queries) {
        answer.push_back(getGene(q[0], q[1]));
    }
    
    return answer;
}
