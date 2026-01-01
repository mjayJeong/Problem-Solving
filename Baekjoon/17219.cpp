#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    unordered_map<string, string> umap;

    for (int i = 0; i < N; i++) {
        string address, pw;
        cin >> address >> pw;
        umap.insert(make_pair(address, pw));
    }

    for (int i = 0; i < M; i++) {
        string finding;
        cin >> finding;

        cout << umap[finding] << '\n';
    }

    return 0;
}
