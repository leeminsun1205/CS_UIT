#include <bits/stdc++.h>
using namespace std;
int main(){
    multimap<string, string> user;
    int soCap, soLan;
    cin >> soCap >> soLan;
    for (int i=0; i<soCap; i++){
        string tk, mk;
        cin >> tk >> mk;
        user.insert({tk,mk});
    }
    vector <string> truyCap(soLan);
    for (int i=0; i<soLan; i++)
        cin >> truyCap[i];
    for (int i=0; i<soLan; i++){
        int j=0;
        for (auto it: user){
            if (truyCap[i]==it.first){
                cout << it.second << " ";
                j++;
            }
        }
        if (j==0) cout << "Chua Dang Ky!";
        cout << endl;
    }
}