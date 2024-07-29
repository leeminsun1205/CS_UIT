#include <iostream>
#include <vector>
using namespace std;

void sinhHoanVi(int i, int n, vector<bool> visited, vector<int> solution){
    for (int j=0; j<n; j++){
        if(visited[j]==0){
            solution.push_back(j+1); 
            visited[j]=1; 
            if (i==n-1){
                for(int k=0; k<solution.size(); k++){
                    cout << solution[k] << " ";
                }
                cout << endl;
            }
            else sinhHoanVi(i+1, n, visited, solution);
            visited[j]=0;
            solution.pop_back();
        }
    }
}
int main(){
    int n;
    cin >> n;
    vector<bool> visited(n, 0); 
    vector<int> solution; 
    sinhHoanVi(0, n, visited, solution);
    return 0;
}