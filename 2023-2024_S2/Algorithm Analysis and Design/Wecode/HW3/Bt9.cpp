#include <bits/stdc++.h>
using namespace std;
vector<vector<bool>> adj_matrix;
int main(){
    int n, q;
    cin >> n >> q;
    int x, y;
    adj_matrix=vector<vector<bool>>(n+1, vector<bool>(n+1, 0));
    vector<int> bac(n+1, 0);
    for(int i=0; i<n-1; i++){
        cin >> x >> y;
        adj_matrix[x][y]=1;
        adj_matrix[y][x]=1;
        bac[x]+=1;
        bac[y]+=1;
    }
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         cout << adj_matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // for(int i=1; i<=n; i++){
    //     cout << bac[i] << " ";
    // }
    for(int i=1; i<=n; i++){
        if
    }
    
}