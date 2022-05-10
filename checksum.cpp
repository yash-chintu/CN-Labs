#include <bits/stdc++.h>
using namespace std;

int binarytodec(vector<int> data)
{
    int dec = 0;
    for (int i = 0; i < data.size(); i++)
    {
        dec = dec * 2;
        if (data[i])
        {
            dec += 1;
        }
    }
    cout << dec << endl;
    return dec;
}

int main()
{
    vector<int> data1 = {0, 0, 0, 1, 1, 0, 0, 1};
    vector<int> data2 = {1, 1, 1, 0, 0, 0, 1, 0};

    int k = 2,
        m = 8;
    vector<int> converted = {binarytodec(data1), binarytodec(data2)};
    vector<int> data(m, 1);
    int high = binarytodec(data);
    int convertedsum = 0;
    for (int i = 0; i < converted.size(); i++)
        convertedsum += converted[i];
    int diff = high - convertedsum;
    if (diff < 0)
    {
        // some code to remove left most bit
    }
    cout << diff << endl;
    return 0;
}