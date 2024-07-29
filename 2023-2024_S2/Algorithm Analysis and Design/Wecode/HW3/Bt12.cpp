#include <bits/stdc++.h>
using namespace std;
vector<int> D_a_C(string expre, int n){
    vector<int> store;
    for(int i=0; i<n; i++){
        if(expre[i]=='+' || expre[i]=='-' || expre[i]=='*'){
            cout << "i = " << i << endl;
            cout << "call part1: ";
            vector<int> part1 = D_a_C(expre.substr(0, i), n);
            cout << "to part1" << endl;
            cout << "call part2: ";
            vector<int> part2 = D_a_C(expre.substr(i+1), n);
            cout << "to part2" << endl;
            for(int x : part1){
                cout << "x = " << x << ": ";
                for(int y: part2){
                    int temp;
                    cout << "y = " << y << ", ";
                    if(expre[i]=='+'){
                        cout << x << " + " << y << " = " << x+y << endl;
                        temp = x + y;
                    }
                    else if(expre[i]=='-'){
                        cout << x << " - " << y << " = " << x-y << endl;
                        temp = x - y;
                    }
                    else if(expre[i]=='*'){
                        cout << x << " * " << y << " = " << x*y << endl;
                        temp = x * y;
                    }
                    store.push_back(temp);
                }
            }
            cout << "store = ";
            for(auto x : store){
                cout << x << ", ";
            }
            cout << endl;
        }
    }
    if(store.size()==0){
        cout << "add number " << stoi(expre) << " ";
        store.push_back(stoi(expre));
    }
    return store;
}
int main(){
    string expre;
    cin >> expre;
    int n = expre.size();
    vector<int> solution = D_a_C(expre, n);
    sort(solution.begin(), solution.end());
    for(int x : solution){
        cout << x << endl;
    }
}