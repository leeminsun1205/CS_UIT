#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> num(n+1);
    for(int i=1; i<=n; i++){
        cin >> num[i];
    }
    vector<int> dp(n+1, 1);
    dp[0]=0;
    vector<int> pre(n+1, 0);
    for(int i=1; i<=n; i++){
        int c=0;
        for(int j=1; j<i; j++){
            if(num[j]<num[i]){
                dp[i]=max(dp[i], dp[j]+1);
                if(dp[j]>dp[c])
                    c=j;
            }
        }
        pre[i]=c;
    }
    int max=1;
    for(int i=2; i<=n; i++){
        if(dp[i]>dp[max]){
            max=i;
        }
    }
    cout << dp[max] << endl;
    vector<int> store;
    while(max!=0){
        store.push_back(max);
        max=pre[max];
    }
    for(int i=store.size()-1; i>=0; i--){
        cout << num[store[i]] << " ";
    }
    return 0;
}