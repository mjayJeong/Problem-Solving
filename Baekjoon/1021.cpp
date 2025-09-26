#include <iostream>
#include <deque>

using namespace std;


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    deque<int> dq;

    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }

    int order[m];
    for (int i = 0; i < m; i++) {
        cin >> order[i];
    }

    int ops = 0;

    for (int i = 0; i < m; i++) {
        int index = 0;
        for (int j = 0; j < dq.size(); j++) {
            if (dq[j] == order[i]) {
                index = j;
                break;
            }
        }

        if (index <= dq.size() / 2) {
            while (index--) {
                dq.push_back(dq.front());
                dq.pop_front();
                ops++;
            }
        } else {
            int r = dq.size() - index;
            while (r--) {
                dq.push_front(dq.back());
                dq.pop_back();
                ops++;
            }
        }
        dq.pop_front();
    }

    cout << ops;

    return 0;
}
