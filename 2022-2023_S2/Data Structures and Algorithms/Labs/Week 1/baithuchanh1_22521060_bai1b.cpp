#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void input(vector <int> &vtr)
{
    for (int i=0; i<vtr.size(); i++)
        cin >> vtr[i];
}
int main()
{
    int n; cin >> n;
    vector <int> vtr(n);
    vector <int> :: iterator it;
    input(vtr);
    int x; cin >> x;
    it=find(vtr.begin(),vtr.end(),x);
    if (it!= vtr.end())
        cout << "Element found in myvector: " << *it << '\n';
    else
        cout << "Element not found in myvector\n";
    return 0;
}