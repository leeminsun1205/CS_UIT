#include <bits/stdc++.h>
using namespace std;
const int M=1e9+7;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int s; 
    cin >> s;
    vector<int> dp(s+1, 0);
    dp[0]=1;
    for(int i=1; i<=s; i++){
        for(int j=1; j<=6; j++){
            if(i>=j){
                dp[i]=(dp[i]+dp[i-j])%M;
            }
        }
    }
    cout << dp[s];
}