#include <iostream>
#include <vector>
using namespace std;
int main(){
    // ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> num(n+1);
    vector<long long> dp(n+1, 0);
    for(int i=1; i<=n; i++){
        cin >> num[i];
        dp[i]=num[i]+dp[i-1];
    }
    int x, y;
    for(int i=0; i<q; i++){
        cin >> x >> y;
        cout << dp[y]-dp[x-1] << '\n';
    }
}