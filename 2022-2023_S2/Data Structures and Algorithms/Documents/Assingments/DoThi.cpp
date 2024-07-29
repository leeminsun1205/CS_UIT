#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; 
    cin >> n;
    map <char, vector<pair<char,int>>> dinh;
    char a, b; int x;
    set<char> diem;
    for (int i=0; i<n; i++){
        cin >> a >> b >> x;
        diem.insert(a);
        diem.insert(b);
        dinh[a].push_back(make_pair(b, x));
    }
    int c, d;
    cin >> c >> d;
    for (auto it : dinh)
    {
        cout << it.first << ": ";
        for (auto x : dinh[it.first])
            cout << x.first << "-" << x.second << " ";
        cout << endl;
    }
    cout << "So dinh la " << diem.size() << endl;
    cout << "Cac dinh cua do thi la: ";
    for (char x: diem){
        cout << x << " ";
    }
    char dinh1, dinh2;
    cin >> dinh1 >> dinh2;
    return 0;
}