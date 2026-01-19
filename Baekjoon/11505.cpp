#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const long long MOD = 1000000007LL;
vector<long long> tree;

void buildTree(int leftStart) {
    for (int i = leftStart - 1; i >= 1; i--) {
        tree[i] = (tree[i * 2] * tree[i * 2 + 1]) % MOD;
    }
}

void changeVal(int index, long long val) {
    tree[index] = val % MOD;   
    index /= 2;
    while (index > 0) {   
        tree[index] = (tree[index * 2] * tree[index * 2 + 1]) % MOD;
        index /= 2;
    }
}

long long getMul(int s, int e) {
    long long partMul = 1;  
    while (s <= e) {
        if (s % 2 == 1) partMul = (partMul * tree[s++]) % MOD;
        if (e % 2 == 0) partMul = (partMul * tree[e--]) % MOD;
        s /= 2;
        e /= 2;
    }
    return partMul;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    int h = 0, len = N;
    while (len > 0) { len /= 2; h++; }

    int size = (int)pow(2, h + 1);
    int leftStart = size / 2;

    tree.assign(size + 1, 1); 

    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        tree[leftStart + i] = x % MOD;
    }

    buildTree(leftStart);

    for (int i = 0; i < M + K; i++) {
        long long a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            changeVal(leftStart + (int)b - 1, c);
        } else {
            int l = leftStart + (int)b - 1;
            int r = leftStart + (int)c - 1;
            cout << getMul(l, r) << "\n";
        }
    }
    return 0;
}
