#include <bits/stdc++.h>
using namespace std;
set<string> n_Date;
void Sort(string & date){
    string temp;
    vector<char> store;
    for(int i=0; i<4; i++){
        store.push_back(date[i]);
    }
    sort(store.begin(), store.end());
    for(int i=0; i<4; i++){
        temp+=store[i];
    }
    temp+=' ';
    if(date[5]<date[6]){
        temp+=date[5];
        temp+=date[6];
    }
    else{
        temp+=date[6];
        temp+=date[5];
    }
    temp+=' ';
    if(date[8]<date[9]){
        temp+=date[8];
        temp+=date[9];
    }
    else{
        temp+=date[9];
        temp+=date[8];
    }
    date=temp;
}
bool isLeapYear(int year){
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
bool checkDate(vector<char> solution){
    int year = (solution[0] - '0')*1000 + (solution[1] - '0')*100 + (solution[2] - '0')*10 + (solution[3] - '0');
    int month = (solution[5] - '0')*10 + (solution[6] - '0');
    int day = (solution[8] - '0')*10 + (solution[9] - '0');

    if (year == 0 || month == 0 || month > 12 || day == 0 || day > 31){
        return false;
    }
    if (month == 2) {
        if (year % 3328 == 0 && day <= 30){
            return true;
        }
        else{
            if (isLeapYear(year)){
                if(day<=29){
                    return true;
                }
            }
            else{
                if(day<=28){
                    return true;
                }
            }
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day <= 30){
            return true;
        }
    }
    else {
        if (day <= 31){
            return true;
        }
    }
    
    return false;
}
void lietKeDate(int i, int n, string date, vector<char> solution, vector<bool> check){
    if(i<4 || i==5 || i == 6 || i == 8 || i == 9){
        for(int j=0; j<10; j++){
            if(j!=4 && j!=7){
                if(check[j]==0){
                    solution.push_back(date[j]);
                    check[j]=1;
                    if (i==n-1&&checkDate(solution)){
                        string date_str(solution.begin(), solution.end());
                        if(n_Date.find(date_str) == n_Date.end()){
                            n_Date.insert(date_str);
                        }
                    }
                    else{
                        lietKeDate(i+1, n, date, solution, check);
                    }
                    check[j]=0;
                    solution.pop_back();
                }
            }
        }
    }
    else if (i==4 || i==7){
        solution.push_back(' ');
        lietKeDate(i+1, n, date, solution, check);
        solution.pop_back();
    }
}
int main(){
    string date;
    getline(cin, date);
    Sort(date);
    vector<char> solution;
    vector<bool> check(date.size(), 0);
    lietKeDate(0, date.size(), date, solution, check);
    cout << n_Date.size() << "\n";
    for(auto x : n_Date){
        cout << x << "\n";
    }
    return 0;
}