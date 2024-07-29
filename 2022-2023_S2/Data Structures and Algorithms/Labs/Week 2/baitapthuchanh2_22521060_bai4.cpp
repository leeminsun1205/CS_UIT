#include <bits/stdc++.h>
using namespace std;
struct Diem
{
    int x, y, z;
};
bool cmp(Diem A, Diem B)
{
    if (A.x == B.x) 
        if (A.y == B.y) return A.z<B.z;
        else return A.y>B.y;
    return A.x<B.x;
}
int main()
{
    int n; cin >> n;
    vector <Diem> vtr(n);
    for (int i=0; i<n; i++)
        cin >> vtr[i].x >> vtr[i].y >> vtr[i].z;
    sort(vtr.begin(),vtr.end(),cmp);
    for (int i=0; i<n; i++)
        cout << vtr[i].x << " " << vtr[i].y << " " << vtr[i].z << endl;
}