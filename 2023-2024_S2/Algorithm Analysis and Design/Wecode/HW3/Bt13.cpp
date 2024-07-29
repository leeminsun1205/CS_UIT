#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> num(n+1);
    for(int i=1; i<=n; i++){
        cin >> num[i];
    }
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int t=1; t<=n; t++){
        for(int i=1; i <= n-t+1; i++){
            int j = i+t-1;
            for(int k=i; k<=j; k++){
                int left = 0, right = 0, num_l = 1, num_r = 1;
                if(i < k) left = dp[i][k-1]; 
                if(k < j) right = dp[k+1][j]; 
                if(1 < i) num_l = num[i-1]; 
                if(j < n) num_r = num[j+1]; 
                dp[i][j] = max(dp[i][j], left + num_l*num[k]*num_r + right);
            }
        }
    }
    cout << dp[1][n];
}