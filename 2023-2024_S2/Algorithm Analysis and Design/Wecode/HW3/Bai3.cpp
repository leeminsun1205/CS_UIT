//Bai toan cai tui
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, s;
    cin >> n >> s;
    vector<int> w(n+1);
    vector<int> v(n+1);
    for(int i=1; i<=n; i++){
        cin >> w[i];
    }
    for(int i=1; i<=n; i++){
        cin >> v[i];
    }
    vector<vector<int>> tongGiaTri(n+1, vector<int>(s+1, 0));
    vector<vector<bool>> decision(n+1, vector<bool>(s, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=s; j++){
            tongGiaTri[i][j]=tongGiaTri[i-1][j];
            if(j>=w[i]){
                tongGiaTri[i][j]=max(tongGiaTri[i][j], tongGiaTri[i-1][j-w[i]]+v[i]);
                decision[i][j]=1;
            }
        }
    }
    // set<int> item;
    // int wei=s;
    // for(int i=n; i>=1; i--){
    //     if(decision[i][wei]){
    //         item.insert(i);
    //         wei-=s-w[i];
    //     }

    // }
    cout << tongGiaTri[n][s];
}