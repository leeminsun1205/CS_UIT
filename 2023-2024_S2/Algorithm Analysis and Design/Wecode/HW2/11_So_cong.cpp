#include <bits/stdc++.h>
using namespace std;

string cut_num(string a, int start, int end){
    string temp="";
    for(int i=start; i<end; i++){
        temp+=a[i];
    }
    return temp;
}
bool checkValid(string num_x){
    if(num_x.size()==1) return true;
    for(int i=0; i<num_x.size(); i++){
        if(num_x[i]=='0'){
            return false;
        }
        return true;
    }
}
void soCong(int i, int part, int sum, int n, string num, vector<string> &solution){
    for(int j=i+1; j<=n; j++){
        string num_x=cut_num(num, i, j);
        if(num_x.size()<=9){
            if (checkValid(num_x)){
                if(part <= 2 || part>=3 && sum==stoi(num_x)){
                    solution.push_back(num_x);
                    sum+=stoi(num_x);
                    if(part>=3){
                        sum-=stoi(solution[part-3]);
                    }
                    if (part >= 3 && j==n){
                        // for(auto x : solution){
                        //     cout << x << " ";
                        // }
                        // cout << endl;
                        return;
                    }
                    else{
                        soCong(j, part+1, sum, n, num, solution);
                    }
                    sum-=stoi(num_x);
                    if(part>=3){
                        sum+=stoi(solution[part-3]);
                    }
                    solution.pop_back();
                }
            }
        }
    }
}
int main(){
    string num;
    cin >> num;
    vector<string> solution;
    soCong(0, 1, 0, num.size(), num, solution);
    if(solution.empty()){
        cout << "false";
    }
    else cout << "true";
    return 0;
}