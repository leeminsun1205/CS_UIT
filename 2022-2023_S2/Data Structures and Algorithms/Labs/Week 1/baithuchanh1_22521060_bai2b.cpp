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
    input(vtr);
    int x; cin >> x;
    sort(vtr.begin(),vtr.end());
    if(binary_search(vtr.begin(),vtr.end(),x))
        cout << "found!";
    else cout << "not found!";
    return 0;
}