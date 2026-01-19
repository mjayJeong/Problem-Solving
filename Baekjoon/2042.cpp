#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> tree;

void buildTree(int leftStart) {
    for (int i = leftStart - 1; i >= 1; i--) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
}

void changeVal(int index, long long val) {
    long long diff = val - tree[index];
    while (index > 0) {
        tree[index] += diff; 
        index /= 2;
    }
}

long long getSum(int s, int e) {
    long long partSum = 0;

    while (s <= e) {
        if (s % 2 == 1) partSum += tree[s++];
        if (e % 2 == 0) partSum += tree[e--];
        s /= 2;
        e /= 2;
    }
    return partSum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    int treeHeight = 0;
    int length = N;

    while (length > 0) {
        length /= 2;
        treeHeight++;
    }

    int treeSize = (int)pow(2, treeHeight + 1);
    int leftNodeStartIndex = treeSize / 2;

    tree.assign(treeSize + 1, 0);

    for (int i = 0; i < N; i++) {
        cin >> tree[leftNodeStartIndex + i];
    }

    buildTree(leftNodeStartIndex);

    for (int i = 0; i < M + K; i++) {
        long long a, s, e;
        cin >> a >> s >> e;

        if (a == 1) {
            changeVal(leftNodeStartIndex + (int)s - 1, e);
        } else {
            int l = leftNodeStartIndex + (int)s - 1;
            int r = leftNodeStartIndex + (int)e - 1;
            cout << getSum(l, r) << '\n';
        }
    }

    return 0;
}
