#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<char> vertices = {'a', 'b', 'c', 'd'};
    vector<pair<pair<char, char>, int>> graph = {{{'a', 'c'}, 6}, {{'a', 'b'}, 6}, {{'a', 'd'}, 6}, {{'b', 'd'}, 2}, {{'c', 'd'}, 2}};
    // from , to , cost

    vector<pair<int, pair<char, char>>> pq; // cost,ver,parent
    pq.push_back({0, {vertices[0], '-'}});
    for (int i = 1; i < 5; i++)
    {
        pq.push_back({INT_MAX, {vertices[i], '-'}});
    }

    vector<char> mstSet;
    vector<char> parentSet;
    vector<int> cost;
    while (pq.size()&&mstSet.size()<vertices.size())
    {
        int high = INT_MAX;
        int index = -1;
        for (int i = 0; i < pq.size(); i++)
        {
            if (pq[i].first < high)
            {
                high = pq[i].first;
                index = i;
            }
        }

        // auto temp = pq.top();
        // pq.pop();
        char currvertex = pq[index].second.first;
        mstSet.push_back(currvertex);
        parentSet.push_back(pq[index].second.second);
        cost.push_back(pq[index].first);
        pq.erase(pq.begin() + index);
        for (int i = 0; i < graph.size(); i++)
        {
            if (graph[i].first.first == currvertex)
            {
                for (int j = 0; j < pq.size(); j++)
                {
                    if (pq[j].second.first == graph[i].first.second)
                    {
                        if (pq[j].first > graph[i].second)
                        {
                            pq[j].first = graph[i].second;
                            pq[j].second.second = currvertex;
                        }
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < mstSet.size(); i++)
    {
        cout << parentSet[i] << "-" << mstSet[i] << ":" << cost[i] << endl;
    }

    return 0;
}