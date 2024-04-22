#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct graph
{
    int start, end, weight;
};

bool Com(graph &a, graph &b)
{
    return a.weight < b.weight;
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<graph> g;

    for (int i = 0; i < e; ++i)
    {
        int start, end, weight;
        cin >> start >> end >> weight;
        g.push_back({start, end, weight});
    }
    sort(g.begin(), g.end(), Com);

    for (auto it : g)
    {
        cout << it.start << " " << it.end << " " << it.weight << endl;
    }
}
