#include <bits/stdc++.h>
using namespace std;
int main(){
    set<int> store;
    int n;
    cin >> n; 
    vector<int> x(n+1);
    for(int i=1; i<=n; i++){
        cin >> x[i];
    }
    set<int> s={0};
    for(int i=1; i<=n; i++){
        set<int> temp;
        for(auto k : s){
            temp.insert(k+x[i]);
        }
        for(auto k : temp){
            s.insert(k);
        }
    }
    s.erase(0);
    cout << s.size() << endl;
    for(auto k : s){
        cout << k << " ";
    }
}
