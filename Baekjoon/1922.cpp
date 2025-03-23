#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int getParent(int parent[], int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int findParent(int parent[], int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a == b) return 1;
    else return 0;
}

class Edge {
public:
    int node[2];
    int distance;
    Edge(int a, int b, int distance) {
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
    }
    bool operator <(Edge &edge) {
        return this->distance < edge.distance;
    }
};


int main()
{
    int n, m;
    vector<Edge> v;
    scanf("%d", &n);
    scanf("%d", &m);


    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v.push_back(Edge(a, b, c));

    }

    sort(v.begin(), v.end());

    // 각 노드를 자기 자신을 부모로
    int set[n];
    for (int i = 0; i < n; i++)
    {
        set[i] = i;
    }

    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (!findParent(set, v[i].node[0]-1, v[i].node[1]-1)) {
            sum += v[i].distance;
            unionParent(set, v[i].node[0]-1, v[i].node[1]-1);
        }
    }

    printf("%d\n", sum);

    return 0;
}
