#include <iostream>
using namespace std;
void input(int vtr[], int &n)
{
    for (int i=0; i<n; i++)
        cin >> vtr[i];
}
void bubbleSort(int vtr[], int &n)
{
    for (int i=0; i<n-1; i++)
        for (int j=0; j<n-i-1; j++)
            if (vtr[j]>vtr[j+1]) 
                swap(vtr[j], vtr[j+1]);
}
int binarySearch(int vtr[], int n, int x)
{
    bubbleSort(vtr, n);
    int left=0, right=n-1;
    while (left<=right)
    {
        int mid=(left+right)/2;
        if (x==vtr[mid]) return mid;
        else if (x<vtr[mid]) right=mid-1;
        else left=mid+1;
    }
    return -1;
}
int main()
{
    int n; cin >> n;
    int  vtr[100];
    input(vtr, n);
    int x,i; cin >> x;
    for (i=0; i<n; i++)
    {
        if (vtr[i]==binarySearch(vtr, n, x)) 
        {
            cout << "found!";
            break;
        }
        if (i==n-1) cout << "not found!";
    }
    return 0;
}