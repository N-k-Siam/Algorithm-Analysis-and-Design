#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> ve;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        ve.push_back({a, b});
    }

    sort(ve.begin(), ve.end(), sortbysec);

    int min = INT_MIN, count = 0;

    for (auto it : ve)
    {
        if (min < it.first)
        {
            cout << it.first << " " << it.second << endl;
            min = it.second;
            ++count;
        }
    }
    cout << "Total Activities: " << count << endl;

    return 0;
}
