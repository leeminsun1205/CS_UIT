#include <bits/stdc++.h>
using namespace std;
void ChuKy(int a[][100], int &n, int b[][100], int m)
{
    int x, y;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
        {
            x=(2*i+j)%n;
            y=(i+j)%n;
            b[i][j]=a[x][y];
        }
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            a[i][j]=b[i][j];
}
bool SoSanh(int a[][100], int n, int b[][100], int m)
{
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (a[i][j]!=b[i][j]) return 0;
    return 1;
}
bool check(int a[][100], int n)
{
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (a[0][0]!=a[i][j]) return 0; 
    return 1;
}
int demK(int a[][100], int n, int b[][100], int m)
{
    int k=1;
    if (check(a,n)==1) return 0;
    else 
    {
        int c[100][100];
        for (int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                c[i][j]=a[i][j];
        ChuKy(a,n,b,m);
        while (SoSanh(c,n,a,m)!=1)
        {
            ChuKy(a,n,b,m);
            k++;
        }
        return k;
    }
}
int main ()
{
    int n, m=n;
    cin >> n;
    int a[100][100], b[100][100];
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> a[i][j];
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            b[i][j]=a[i][j];    
    cout << demK(a,n,b,m);
    return 0;
}