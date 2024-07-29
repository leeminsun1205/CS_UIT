#include <iostream>
using namespace std;
int linearSearch(int vtr[], int n, int x)
{
    for(int i=0; i<n; i++)
        if (vtr[i]==x) return i;
    return -1;
}
void input(int vtr[], int &n)
{
    for (int i=0; i<n; i++)
        cin >> vtr[i];
}
int main ()
{
    int n; cin >> n;
    int  vtr[100];
    input(vtr, n);
    int x; cin >> x;
    cout << linearSearch(vtr, n, x);
    return 0;
}