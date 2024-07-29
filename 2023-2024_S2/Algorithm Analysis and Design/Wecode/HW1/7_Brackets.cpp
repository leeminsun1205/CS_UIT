#include <iostream>
#include <vector>
using namespace std;

void brackets(int n, int open_bra, int close_bra, vector<string> solution){
    for(int j=0; j<2; j++){
        if ((j==0 && open_bra < n) || (j==1 && open_bra > close_bra)){
            if (j==0 && open_bra < n){
                solution.push_back("(");
            }
            else if (j==1 && open_bra > close_bra){
                solution.push_back(")");
            } 
            if (close_bra+open_bra+1==2*n){
                for(auto x : solution){
                    cout << x;
                }
                cout << endl;
            }
            else{
                brackets(n, open_bra+!j, close_bra+j, solution);
            }
            solution.pop_back();
        }
    }
}
int main(){
    int n;
    cin >> n;
    vector<string> solution;
    brackets(n, 0, 0, solution);
    return 0;
}