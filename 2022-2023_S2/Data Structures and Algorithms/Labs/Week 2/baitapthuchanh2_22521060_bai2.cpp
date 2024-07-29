#include <bits/stdc++.h>
using namespace std;
void insertionSort(vector <int> &vtr, int n)
{
    for (int i=1; i<n; i++)
    {
        int x=vtr[i], pos=i-1;
        while (pos >=0 && x<vtr[pos])
        {
            vtr[pos+1]=vtr[pos];
            --pos;
        }
        vtr[pos+1]=x;
    }
}
int main()
{
    int n; cin >> n;
    vector <int> vtr(n);
    srand(time(NULL));
    for (int i=0; i<n; i++)
        vtr[i]=rand()%1000;
    insertionSort(vtr,n);
    for (int i=0; i<n; i++)
        cout << vtr[i] << " ";
    return 0;
}