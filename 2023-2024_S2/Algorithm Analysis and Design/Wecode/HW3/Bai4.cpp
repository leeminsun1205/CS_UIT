//Bai toan day con tang dai nhat
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; 
    cin >> n;
    vector<int> day(n);
    for(int i=0; i<n; i++){
        cin >> day[i];
    }
    vector<int> L(n, 1);
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(day[j]<day[i]){
                L[i]=max(L[i], L[j]+1);
            }
        }
    }
    cout << *max_element(L.begin(), L.end()) << endl;
}