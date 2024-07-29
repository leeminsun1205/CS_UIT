#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> num(n+1);
    for(int i=1; i<=n; i++){
        cin >> num[i];
    }
    vector<int> dp(n+1, 1);
    int Max=dp[1];
    for(int i=2; i<=n; i++){
        for(int j=1; j<i; j++){
            if(num[j]<num[i]){
                dp[i]=max(dp[i], dp[j]+1);
            }
        }
        if(dp[i]>Max){
            Max=dp[i];
        }
    }
    cout << Max;
    return 0;
}