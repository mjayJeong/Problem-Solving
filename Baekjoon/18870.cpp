#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// &로 참조 전달해야함
int binarySearch(vector<int>& v, int target) { 
    int left = 0;
    int right = v.size();
    while (left < right) {
        int mid = (left + right) / 2;
        if (v[mid] >= target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main()
{
    int n; 
    cin >> n;
    vector<int> cor(n);
    vector<int> sorted_cor;
    for (int i = 0; i < n; i++) {
        cin >> cor[i];
    }
    sorted_cor = cor;
    sort(sorted_cor.begin(), sorted_cor.end());
    sorted_cor.erase(unique(sorted_cor.begin(), sorted_cor.end()), sorted_cor.end());    // 중복 제거 필수

    for (int j = 0; j < n; j++) {
        cout << binarySearch(sorted_cor, cor[j]) << ' ';
    }

    return 0;
}
