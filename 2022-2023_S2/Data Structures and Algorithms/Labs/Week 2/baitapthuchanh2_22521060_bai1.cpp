#include <bits/stdc++.h>
using namespace std;
void selectionSort(vector <int> &vtr, int n)
{
    for (int i=1; i<n; i++)
    {
        int min=i-1;
        for (int j=i; j<n; j++)
            if (vtr[j]<vtr[min]) min=j;
        swap(vtr[i-1],vtr[min]);
    }
}
int main()
{
    int n; cin >> n;
    vector <int> vtr(n);
    srand(time(NULL));
    for (int i=0; i<n; i++)
        vtr[i]=rand()%1000;
    selectionSort(vtr,n);
    for (int i=0; i<n; i++)
        cout << vtr[i] << " ";
    return 0;
}