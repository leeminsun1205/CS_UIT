#include <iostream>
#include <vector>
#include <string>
using namespace std;
int count=0;

int max(vector<int> a){
    int max = a[0];
    for(int i=1; i<a.size(); i++){
        if(a[i]>max){
            max = a[i];
        }
    }
    return max;
}
int min(vector<int> a){
    int min = 0;
    for(int i=1; i<a.size(); i++){
        if(a[i]<a[min]){
            min = i;
        }
    }
    return min;
}

void process(int i, int n, int m, vector<int> solution, vector<int> jobs, vector<int> sum, vector<int> &store, vector<vector<int>> &result){
    for(int j=0; j<m; j++){
        solution.push_back(j);
        if (i==n-1){
            for(int k=0; k<n; k++){
                sum[solution[k]]+=jobs[k];
            }       
            if(count==0){
                store.push_back(max(sum));
                result.push_back(solution);
                count++;
            }
            else{
                store.push_back(max(sum));
                int Min = min(store);
                // cout << Min << " ";
                if(Min==1){
                    store[0]=store[1];
                    result.push_back(solution);
                    for(int i=0; i<n; i++){
                        result[0][i]=result[1][i];
                    }
                    result.pop_back();
                }
                store.pop_back();
            }

        }
        else{
            process(i+1, n, m, solution, jobs, sum, store, result);
        }
        solution.pop_back();
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> jobs(n);
    for(int i=0; i<n; i++){
        cin >> jobs[i];
    }
    vector<int> solution;
    vector<int> sum(m, 0);
    vector<int> store;
    vector<vector<int>> result;
    process(0, n, m, solution, jobs, sum, store, result);
    for(int i=0; i<n; i++){
        cout<< result[0][i] << " ";
    }
    return 0;
}