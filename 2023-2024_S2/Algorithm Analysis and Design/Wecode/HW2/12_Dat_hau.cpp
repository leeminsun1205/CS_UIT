#include <bits/stdc++.h>
using namespace std;

bool Check(int i, int j, int n, vector<vector<char>> solution){
    for(int k=i-1; k>=0; k--){
        if(solution[k][j]=='X'){
            return false;
        }
    }
    int a=1;
    while(i-a>=0 && j-a>=0){
        if(solution[i-a][j-a]=='X'){
            return false;
        }
        a++;
    }
    int c=1;
    while(i-c>=0 && j+c<n){
        if(solution[i-c][j+c]=='X'){
            return false;
        }
        c++;
    }
    return true;
}

bool findS=false;
void datHau(int i, int n, vector<vector<char>> solution){
    if(findS==true) return;
    if(i==0){
        for(int j=0; j<n; j++){
            solution[i][j]='X';
            datHau(i+1, n, solution);
            solution[i][j]='.';
        }
    }
    else if(i>0){
        for(int j=0; j<n; j++){
            if(Check(i, j, n, solution)){
                solution[i][j]='X';
                if(i==n-1){
                    for(int i=0; i<n; i++){
                        for(int j=0; j<n; j++){
                            cout << solution[i][j];
                        }
                        cout << endl;
                    }
                    // cout << endl;
                    findS=true;
                }
                else datHau(i+1, n, solution);
                solution[i][j]='.';
            }
        }
    }
}
int main(){
    int n; 
    cin >> n;
    vector<vector<char>> solution(n, vector<char>(n, '.'));
    datHau(0, n, solution);
    return 0;
}