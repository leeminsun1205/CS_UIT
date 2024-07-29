#include <iostream>
#include <vector>
using namespace std;

void transform_and_store(int n, vector<int> &store){
    while(n!=0){
        store.push_back(n%10);
        n/=10;
    }
}

void hoanVi(int i, int n, vector<bool> check, vector<int> solution, vector<int> store){
    for (int j=0; j<n; j++){
        if(check[j]==0){
            solution.push_back(store[j]);
            check[j]=1;
            if (i==n-1){
                for(int k=0; k<solution.size(); k++){
                    cout << solution[k];
                }
                cout << endl;
            }
            else hoanVi(i+1, n, check, solution, store);
            check[j]=0;
            solution.pop_back();
        }
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> store;
    transform_and_store(n, store);
    vector<bool> check(store.size(), 0);
    vector<int> solution;
    hoanVi(0, store.size(), check, solution, store);
    return 0;
}