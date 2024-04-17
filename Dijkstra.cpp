#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int dis[N], visited[N] = {0}, parent[N] = {0};
int k = 0;

void Print_parent(int a)
{
    if (a == 0)
    {
        cout << parent[0] << " ";
        return;
    }
    else
    {
        Print_parent(parent[a]);
        cout << a << " ";
    }
}
void MAX_array(int node)
{
    for (int i = 0; i < node; i++)
    {
        dis[i] = INT_MAX;
    }
}

void visiting(vector<vector<int>> v1, int start, int node)
{
    ++k;
    if (k == node)
    {
        return;
    }
    for (int i = 0; i < node; ++i)
    {
        if (v1[start][i] != 0)
        {
            if ((dis[start] + v1[start][i]) < dis[i])
            {
                parent[i] = start;
                dis[i] = dis[start] + v1[start][i];
            }
        }
    }
    int index = 0, min = INT_MAX;
    for (int i = 0; i < node; ++i)
    {
        if (visited[i] != 1 && min > dis[i])
        {
            min = dis[i];
            index = i;
        }
    }
    visited[index] = 1;
    visiting(v1, index, node);
}

int main()
{
    int node, edge;
    cin >> node >> edge;

    vector<vector<int>> v1(node, vector<int>(node, 0));
    for (int i = 0; i < edge; ++i)
    {
        int start, end, weight;
        cin >> start >> end >> weight;
        v1[start][end] = weight;
        v1[end][start] = weight;
    }

    MAX_array(node);
    visited[0] = 1;
    dis[0] = 0;
    visiting(v1, 0, node);

    for (int i = 0; i < node; ++i)
    {
        cout << "NODE: " << i << endl;

        cout << "Distance : " << dis[i] << endl;
        cout << "Parents: ";
        Print_parent(i);
        cout << endl
             << endl;
    }

    return 0;
}
