#include <bits/stdc++.h>
using namespace std;
#define MAX 500
void inputArr(int arr[][MAX], int &m, int &n)
{
    cin >> m >> n;
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            cin >> arr[i][j];
}
unsigned int countHangXom(int arr[][MAX], int row, int col)
{
    unsigned int count=0;
    for (int i=row-1; i<=row+1; i++)
        for (int j=col-1; j<=col+1; j++)
            if (arr[i][j]==1){ 
                count ++;
            }
    if (arr[row][col]==1) count--;
    return count;
}
void outputArr(int arr[][MAX], int m, int n)
{
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
void update(int arr[][MAX], int &m, int &n)
{
    int arr2[MAX][MAX];
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            arr2[i][j]=arr[i][j];
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            if (arr2[i][j]==0 && countHangXom(arr2,i,j)==3) 
                arr[i][j]=1;
            else{
                if (countHangXom(arr2,i,j) <2 || countHangXom(arr2,i,j) >3) arr[i][j]=0;
            }
}
int main()
{
    int arr[MAX][MAX], m, n;
    inputArr(arr, m, n);
    int k; cin >> k;
    for (int i=1; i<=k; i++)
        update(arr,m,n);
    outputArr(arr,m,n);
    return 0;
}