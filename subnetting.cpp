#include <bits/stdc++.h>
using namespace std;

int binarytoDecimal(vector<int> bits)
{
    int dec = 0;
    for (int i = bits.size() - 1; i >= 0; i--)
    {
        dec = (dec * 2);
        if (bits[i])
            dec = dec + 1;
    }
    return dec;
}

int main()
{
    vector<int> ip, subnetmask;
    int subnets;
    int Class = 0; // 1-class A,2-class B, 3-class C
    cout << "enter IP :" << endl;
    for (int i = 0; i < 4; i++)
    {
        int temp;
        cin >> temp;
        ip.push_back(temp);
    }
    cout << "Enter number of subnets :" << endl;
    cin >> subnets;

    int noofsubnetbits;

    if (log2(subnets) == (int)log2(subnets))
    {
        noofsubnetbits = log2(subnets);
    }
    vector<int> subnetbits(8, 0);
    int i = 7;
    while (noofsubnetbits--)
    {
        subnetbits[i--] = 1;
    }

    if (ip[0] < 128)
    {
        Class = 1;
        subnetmask.push_back(255);
        subnetmask.push_back(binarytoDecimal(subnetbits));
        subnetmask.push_back(0);
        subnetmask.push_back(0);
    }
    else if (ip[0] < 192)
    {
        Class = 2;
        subnetmask.push_back(255);
        subnetmask.push_back(255);
        subnetmask.push_back(binarytoDecimal(subnetbits));
        subnetmask.push_back(0);
    }
    else
    {
        Class = 3;
        subnetmask.push_back(255);
        subnetmask.push_back(255);
        subnetmask.push_back(255);
        subnetmask.push_back(binarytoDecimal(subnetbits));
    }

    for (i = 0; i < 4; i++)
        cout << subnetmask[i] << endl;

    return 0;
}