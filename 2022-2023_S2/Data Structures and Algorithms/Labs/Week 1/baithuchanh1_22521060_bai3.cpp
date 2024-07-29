#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void input(vector <int> &vtr)
{
    for (int i=0; i<vtr.size(); i++)
        cin >> vtr[i];
}
void check(vector <int> vtr, vector <int> Q)
{
    for (int i=0; i<Q.size(); i++)
        if (binary_search(vtr.begin(),vtr.end(), Q[i])) 
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
}
int main()
{
    int n; cin >> n;
    int m; cin >> m;
    vector <int> vtr(n);
    vector <int> Q(m);
    input(vtr);
    input(Q);
    sort(vtr.begin(),vtr.end());
    check(vtr,Q);
    return 0;
}