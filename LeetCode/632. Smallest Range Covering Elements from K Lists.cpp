#include <queue>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int N = nums.size();

        // (value, listIndex, elementIndex)
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<>
        > pq;

        int currentMax = INT_MIN;

        // 초기 세팅
        for (int i = 0; i < N; i++) {
            pq.push({nums[i][0], i, 0});
            currentMax = max(currentMax, nums[i][0]);
        }

        vector<int> answer = {0, INT_MAX};

        while (pq.size() == N) {
            auto [val, listIdx, elemIdx] = pq.top();
            pq.pop();

            // 구간 갱신
            if (currentMax - val < answer[1] - answer[0]) {
                answer[0] = val;
                answer[1] = currentMax;
            }

            // 다음 원소 존재하면 push
            if (elemIdx + 1 < nums[listIdx].size()) {
                int nextVal = nums[listIdx][elemIdx + 1];
                pq.push({nextVal, listIdx, elemIdx + 1});
                currentMax = max(currentMax, nextVal);
            } else {
                break; // 하나라도 끝나면 종료
            }
        }

        return answer;
    }
};
