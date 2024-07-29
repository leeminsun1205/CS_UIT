#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    long long n;
    cin >> n;
    vector<long long> fibo(n+1, 0);
    fibo[1]=1;
    fibo[2]=1;
    for(int i=3; i<=n; i++){
        fibo[i]=fibo[i-1]+fibo[i-2];
    }
    cout << fibo[n];
    return 0;
}