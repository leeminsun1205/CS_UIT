#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int min(vector<int> a){
    int min = 0;
    for(int i=1; i<a.size(); i++)
        if(a[i]<a[min]){
            min=i;
        }
    return min;
}
int max(vector<vector<int>> a, int k, int n){
    int max = a[k][0];
    for(int i=1; i<n; i++){
        if (a[k][i]>=max){
            max=a[k][i];
        }
    }
    return max;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> jobs;
    jobs=vector<vector<int>>(m, vector<int>(n,0));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> jobs[i][j];
        }
    }
    vector<int> solution(n, 0);
    vector<int> machine(m, 0);
    vector<int> store(n, 0);
    int k;
    for(int i=0; i<n; i++){
        int idm=min(machine);
        for(int j=0; j<n; j++){
            store[j]=jobs[idm][j];
        }
        k=min(store); 
        solution[k]=idm;
        machine[idm]+=store[k];
        for(int t=0; t<m; t++){
            jobs[t][k]=max(jobs, t, n);
        }
    }
    for(auto it : solution){
        cout << it << " ";
    }
    return 0;
}