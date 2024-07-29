#include <bits/stdc++.h>
using namespace std;
int main(){
    int soMa;
    set<int> ma;
    int n; cin >> n;
    for (int i=0; i<n; i++){
        int x; cin >> x;
        ma.insert(x);
    }
    cout << ma.size();
    return 0;
}