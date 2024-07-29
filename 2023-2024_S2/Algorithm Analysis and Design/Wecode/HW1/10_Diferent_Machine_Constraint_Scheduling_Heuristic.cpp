#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
    for(int i=0; i<n; i++){
        int min=0;
        for(int j=1; j<m; j++){
            if (jobs[min][i]==-1){
                min=j;
            }
            else{
                if(jobs[j][i]>0&&(machine[j]+jobs[j][i]<machine[min]+jobs[min][i])){
                    min = j;
                }
            }
        }
        solution[i]=min;
        machine[min]+=jobs[min][i];
    }
    for(auto it : solution){
        cout << it << " ";
    }
    return 0;
}