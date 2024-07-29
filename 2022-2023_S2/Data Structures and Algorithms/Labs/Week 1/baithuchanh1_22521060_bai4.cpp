#include <bits/stdc++.h>
using namespace std;
struct Point
{
    int x;
    int y;
};
istream &operator >> (istream &in, Point &P)
{
    cin >> P.x >> P.y;
    return in;
}
ostream &operator << (ostream &out, Point P)
{
    cout << P.x << " " << P.y;
    return out;
}
bool cmp(Point A, Point B)
{
    if (A.x==B.x) 
        return A.y > B.y;
    else 
        return A.x < B.x;
}
int main()
{
    int n; cin >> n;
    vector <Point> P(n);
    for (int i=0; i<n; i++)
        cin >> P[i];
    sort(P.begin(),P.end(),cmp);
    for (int i=0; i<n; i++)
        cout << P[i] << endl;
    return 0;
}