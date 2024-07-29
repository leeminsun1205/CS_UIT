#include <bits/stdc++.h>
using namespace std;
int MEX(vector <int> count, int m)
{
    for (int i=0; i<=m; i++)
        {
            if(count[i]==0) return i;
        }
    return m+1;
}
int main()
{
    int n; cin >> n;
    vector <int> vtr(n);
    vector <int> count(n); 
    int m=0;
    for (int i=0; i<n; i++)
    {
        cin >> vtr[i];
        count[vtr[i]]=1;
        m=max(m,vtr[i]);
    }
    cout << MEX (count, m);
    return 0;
}