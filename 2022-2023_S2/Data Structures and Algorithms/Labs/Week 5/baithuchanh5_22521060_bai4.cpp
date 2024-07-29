#include <bits/stdc++.h>
using namespace std;
int main(){
    // freopen("flowers.inp", "r", stdin);
    // freopen("flowers.out", "r", stdout);
    int n, k;
    cin >> n >> k;
    map<int, int> den;
    for (int i=0; i<n; i++){
        int x;
        cin >> x;
        den[x]++;
    }
    while(k!=0){
        for (auto it: den){
            if (it.second>0){
                cout << it.first << " ";
                den[it.first]=it.second-1;
            }
            k--;
            if (k==0) break;
        }
    }
    return 0;
}