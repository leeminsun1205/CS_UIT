#include <iostream>
#include <vector>
#include <string>
using namespace std;

string cut_string(string a, int start, int end){
    string temp="";
    for(int i=0; i<a.size(); i++){
        if (start<=i&&i<end){
            temp+=a[i];
        }
    }
    return temp;
}
bool check_valid(string sub){
    int valid=stoi(sub);
    if(0<=valid && valid<=255){
        if(sub.size()==2 && sub[0]=='0' || sub.size()==3 && (sub[0]=='0' || sub[0]=='0' && sub[1]=='0'))
            return 0;
        return 1;
    }
    return 0;
}
void IP_process(int i, int part, string wrong_IP, vector<string> solution, vector<bool> check){
    for(int j=i+1; j<=wrong_IP.size(); j++){
        string sub=cut_string(wrong_IP, i, j);
        if(sub.size()<=3){
            if(check_valid(sub)){
                if (part<=3)
                    solution.push_back(sub + ".");
                else 
                    solution.push_back(sub);
                if(part==4 && j==wrong_IP.size()){
                    for(auto x : solution){
                        cout << x;
                    }
                    cout << endl;
                }
                else{
                    IP_process(j, part+1, wrong_IP, solution, check);
                }
                solution.pop_back();
            }
        }
    }
}
int main(){
    string wrong_IP;
    cin >> wrong_IP;
    if (wrong_IP.size()<=12){
        vector<bool> check(wrong_IP.size()-1, 0);
        vector<string> solution;
        IP_process(0, 1, wrong_IP, solution, check);
    }
    return 0;
}