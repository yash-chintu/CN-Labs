#include <bits/stdc++.h>

using namespace std;

struct distTable
{
    int dist[5];
    char next_hop[5];
} tables[5];

int main()
{
    int n;
    cin >> n;
    vector<char> chars = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    vector<vector<int>> neighbours(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        vector<int> neighs;
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            matrix[i][j] = temp;
            tables[i].dist[j] = temp;
            tables[i].next_hop[j] = chars[j];
            if (temp != 999 && temp != 0)
            {
                neighs.push_back(j);
            }
        }
        neighbours[i] = neighs;
        matrix[i][i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < neighbours[i].size(); j++)
        {
            for (int k = 0; k < n; k++)
            {
                // if (tables[i].dist[k] > tables[i].dist[j] + tables[j].dist[k])
                if (tables[i].dist[k] > matrix[i][neighbours[i][j]] + matrix[neighbours[i][j]][k])
                {
                    tables[i].dist[k] = tables[i].dist[neighbours[i][j]] + tables[neighbours[i][j]].dist[k];
                    tables[i].next_hop[k] = chars[neighbours[i][j]];
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << chars[i] << tables[2].dist[i] << tables[2].next_hop[i] << endl;
    }

    return 0;
}