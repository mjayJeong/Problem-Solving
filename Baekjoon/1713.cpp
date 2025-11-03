#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    int num;
    int vote;
    int time;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, total;
    cin >> N >> total;
    vector<Student> frame;
    int time = 0;

    for (int i = 0; i < total; i++) {
        int num;
        cin >> num;
        time++;

        bool exist = false;
        for (auto &f : frame) {
            if (f.num == num) {
                f.vote++;
                exist = true;
                break;
            }
        }
        
        if (exist) continue;

        // 사진들이 비어있을 경우 
        if (frame.size() < N) {
            frame.push_back({num, 1, time});
        } else {
            int idx = 0;
            for (int j = 1; j < frame.size(); j++) {
                if (frame[j].vote < frame[idx].vote || (frame[j].vote == frame[idx].vote && frame[j].time < frame[idx].time)) {
                    idx = j;
                }
            }
            frame.erase(frame.begin() + idx);
            frame.push_back({num, 1, time});
        }
    }
    vector<int> result;
    for (auto &f : frame) {
        result.push_back(f.num);
    }
    sort(result.begin(), result.end());

    for (int x : result) {
        cout << x << ' ';
    }

    return 0;   
}
