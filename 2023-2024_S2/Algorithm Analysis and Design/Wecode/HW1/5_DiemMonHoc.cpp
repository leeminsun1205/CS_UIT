#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
double roundScore(double f){
    f = round(f*1000)/1000;
    f = round(f*10)/10;
    return f;
}
void tinhDiem(int s, double i, double sum, int n, vector<double> solution, vector<double> weights){
    if (roundScore(sum)<=i){
        for(double j=0.25; j<=10; j+=0.25){
            solution.push_back(j);
            sum+=weights[s]/100.0*j;
            if(s==n-1){
                if (roundScore(sum)==i){
                    for(int k=0; k<n; k++){
                        cout << solution[k] << " ";
                    }
                    cout << endl;
                }
            }
            else tinhDiem(s+1,i, sum, n, solution, weights);
            sum-=weights[s]/100.0*j;
            solution.pop_back();
        }
    }
}
int main(){
    int n;
    cin >> n;
    double i;
    vector<double> weights(n);
    for (int i=0; i<n; i++){
        cin >> weights[i];
        weights[i];
    }
    cin >> i;
    vector<double> solution;
    tinhDiem(0,i, 0, n, solution, weights);
    return 0;
}