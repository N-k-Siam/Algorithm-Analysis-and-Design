#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int parent[N], Rank[N];

void make_set(int v) {
    parent[v] = v;
    Rank[v] = 0;
}

int find_set(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (Rank[a] < Rank[b])
            swap(a, b);
        parent[b] = a;
        if (Rank[a] == Rank[b])
            Rank[a]++;
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    vector<pair<int, pair<int, int>>> graph(e);
    for (int i = 0; i < e; ++i) {
        int start, end, weight;
        cin >> start >> end >> weight;
        make_set(start);
        make_set(end);
        graph.push_back({weight, {start, end}});
    }

    sort(graph.begin(), graph.end());

    int totalCost = 0;
    for (const auto &edge : graph) {
        int weight = edge.first;
        int start = edge.second.first;
        int end = edge.second.second;

        if (find_set(start) != find_set(end)) {
            union_sets(start, end);
            totalCost += weight;
            cout << start << " " << end << " " << weight << endl;
        }
    }

    cout << "Total cost of the MST: " << totalCost << endl;

    return 0;
}
