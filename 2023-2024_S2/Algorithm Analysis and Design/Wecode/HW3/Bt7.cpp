#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, W;
    cin >> n >> W;
    vector<int> w(n+1);
    vector<int> v(n+1);
    for(int i=1; i<=n; i++){
        cin >> w[i];
    }
    for(int i=1; i<=n; i++){
        cin >> v[i];
    }
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=W; j++){
            dp[i][j]=dp[i-1][j];
            if(w[i]<=j){
                dp[i][j]=max(dp[i][j], dp[i-1][j-w[i]]+v[i]);
            }
        }
    }
    cout << dp[n][W];
}