#include <bits/stdc++.h>
using namespace std;
struct Pj{
    int a, b, p;
};
int bin_search(vector<Pj> &proj, int i){
    int left=1, right=i-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(proj[mid].b<proj[i].a){
            if(proj[mid+1].b<proj[i].a){
                left=mid+1;
            }
            else return mid;
        }
        else{
            right=mid-1;
        }
    }
    return 0;
}
bool compare(Pj &x, Pj &y){
    return x.b < y.b;
}
int main(){
    int n;
    cin >> n;
    vector<Pj> proj(n+1);
    for(int i=1; i<=n; i++){
        cin >> proj[i].a >> proj[i].b >> proj[i].p;
    }
    sort(proj.begin()+1, proj.end(), compare);
    vector<long long> dp(n+1, 0);
    for(int i=1; i<=n; i++){
        int p_i=proj[i].p;
        // đồ án không được chọn
        dp[i]=dp[i-1];
        // chọn đồ án 
        int f=bin_search(proj, i);
        // lấy tổng số tính chỉ lớn hơn
        dp[i]=max(dp[i], dp[f]+p_i);
    }
    cout << dp[n];
}