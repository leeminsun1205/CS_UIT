#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, sum;
    cin >> n >> sum;
    vector<int> num(n+1);
    for(int i=1; i<=n; i++){
        cin >> num[i];
    }
    vector<vector<bool>> solution(n+1, vector<bool>(sum+1, 0));
    for(int i=0; i<=n; i++){
        solution[i][0]=1;
    }
    for(int i=1; i<=n; i++){
        for(int j=sum; j>=num[i]; j--){
            if(solution[i][j-num[i]]==1){
                solution[i][j]=1;
            }
            // solution[i+1][j]=1;
        }
    }
    for(int i=0; i<=n; i++){
        if(solution[i][sum]==1){
            cout << 1;
            break;
        }
    }
    return 0;
}