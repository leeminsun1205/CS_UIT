#include <bits/stdc++.h>
using namespace std;
map<char, vector<pair<char, int>>> DSKe;
set<char> dinh;
bool kt(char u, char v){
    for (auto x : DSKe[u]){
        if (x.first=v)
            return true;
    }
    for (auto x : DSKe[v]){
        if (x.first=u)
            return true;
    }
    return false;
}
int main(){
    int n;
    cin >>n;
    char u, v;
    int w;
    for (int i=0; i<n; i++){
        cin >> u >> v >> w;
        DSKe[u].push_back(make_pair(v,w));
        dinh.insert(u);
        dinh.insert(v);
    }
    for (auto x : DSKe){
        cout << x.first << ": ";
        for (auto y : DSKe[x.first]){
            cout << y.first << "-" << y.second << " ";
        }
        cout << endl;
    }
    cin >> u >> v;
    if (kt(u,v)==1) cout << "Hai dinh ke nhau!";
    else cout << "Hai dinh khong ke nhau!";
    return 0;
}