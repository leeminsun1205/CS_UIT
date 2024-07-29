#include <bits/stdc++.h>
using namespace std;
int main(){
    string n, m;
    cin >> n >> m;
    int N=n.size(), M=m.size();
    vector<vector<int>> dp(N+1, vector<int>(M+1, 0));
    for(int i=0; i<=N; i++){
        dp[i][0]=i;
    }
    for(int j=1; j<=M; j++){
        dp[0][j]=j;
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(n[i-1]==m[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1])+1;
            }
        }
    }
    cout << dp[N][M];
    return 0;
}