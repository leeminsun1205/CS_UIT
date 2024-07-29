#include <bits/stdc++.h>
using namespace std;
int main(){
    map<string, string> user;
    int soCap, soLan;
    cin >> soCap >> soLan;
    for (int i=0; i<soCap; i++){
        string tk, mk;
        cin >> tk >> mk;
        user[tk]=mk;
    }
    vector <string> truyCap(soLan);
    for (int i=0; i<soLan; i++)
        cin >> truyCap[i];
    for (int i=0; i<soLan; i++){
        if (user.count(truyCap[i])!=0){
            cout << user[truyCap[i]] << endl;
        }
        else 
            cout << "Chua Dang Ky!\n";
    }
}