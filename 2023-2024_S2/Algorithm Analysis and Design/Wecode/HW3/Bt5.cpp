#include <bits/stdc++.h>
using namespace std; 
const int M=1e9+7;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<vector<char>> map(n+1, vector<char>(n+1));
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> map[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        if(map[1][i]!='*'){
            dp[1][i]=1;
        }
        else break;
    }
    for(int i=1; i<=n; i++){
        if(map[i][1]!='*'){
            dp[i][1]=1;
        }
        else break;
    }
    
    for(int i=2; i<=n; i++){
        for(int j=2; j<=n; j++){
            if(map[i][j]!='*'){
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%M;
            }
        }
    }
    cout << dp[n][n];
}