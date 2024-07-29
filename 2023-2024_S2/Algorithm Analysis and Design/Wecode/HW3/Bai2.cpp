#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<vector<long long>> C(n+1, vector<long long>(k+1, 0));
    
    for(int i=0; i<=n; i++){
        C[i][0]=1;
    }
    for(int i=0; i<=n; i++){
        C[i][i]=1;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j<=k; j++){
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    cout << C[n][k];
    return 0;
}