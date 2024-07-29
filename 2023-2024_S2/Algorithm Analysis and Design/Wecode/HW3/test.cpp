#include <bits/stdc++.h>
using namespace std;
int findMax(int a[], int l, int r)
{ if(l==r) return a[l];
 int m=(l+r)/2;
 if(a[m]<a[m+1]) 
 return findMax(a,m+1,r);
 else if(a[m]>a[m+1]) 
 return findMax(a,l,m);
 else return max(findMax(a,m+1,r), findMax(a,l,m));
}
int main(){
    int a[100];
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cout << findMax(a, 0, n-1);
    return 0;
}