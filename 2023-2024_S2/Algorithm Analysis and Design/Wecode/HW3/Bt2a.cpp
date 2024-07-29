#include <bits/stdc++.h>
using namespace std;
int bin_search(vector<int> &num, vector<int> &b, int l_num, int num_i){
    int i=0, left=1, right=l_num;
    while(left<=right){
        int mid=(left+right)/2;
        if(num[b[mid]]<num_i){
            i=mid;
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return i;
}
int main(){
    int n;
    cin >> n;
    vector<int> num(n+1);
    for(int i=1; i<=n; i++){
        cin >> num[i];
    }
    int l_num = 1;
    vector<int> dp(n+1, 0);
    vector<int> b(n+1, 0);
    b[1] = 1;
    for(int i=1; i<=n; i++){
        int f=bin_search(num, b, l_num, num[i])+1;
        if(num[b[f]]>num[i] || f>l_num){
            b[f]=i;
            if(f>l_num)
                l_num=f;
        }
        dp[i]=f;
    }
    int Max=dp[1];
    for(int i=2; i<=n; i++){
        if(dp[i]>Max){
            Max=dp[i];
        }
    }
    cout << Max;
}