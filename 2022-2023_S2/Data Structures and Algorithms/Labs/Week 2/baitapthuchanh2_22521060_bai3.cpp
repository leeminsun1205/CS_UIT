#include <bits/stdc++.h>
using namespace std;
int partition(vector <int> &vtr, int l, int r)
{
    int pivot=vtr[l];
    int i=l-1, j=r+1;
    while(1)
    {
        do{
            i++;
        }while(vtr[i]<pivot);
        do{
            j--;
        }while(vtr[j]>pivot);
        if(i<j){
            swap(vtr[i],vtr[j]);
        }
        else return j;
    }
}
void quickSort(vector <int> &vtr, int l, int r)
{
    if (l>=r) return;
    int p=partition(vtr, l, r);
    quickSort(vtr, l, p);
    quickSort(vtr, p+1, r);
}
int main()
{
    int n; cin >> n;
    vector <int> vtr(n);
    srand(time(NULL));
    for (int i=0; i<n; i++)
        vtr[i]= rand()%1000;
    quickSort(vtr,0,n-1);
    for (int i=0; i<n; i++)
        cout << vtr[i] << " ";
    return 0;
}