#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
bool customCompare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first > b.first;
}

int min(vector<int> a){
    int min = 0;
    for(int i=1; i<a.size(); i++)
        if(a[i]<a[min]){
            min=i;
        }
    return min;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> time(n);
    for(int i=0; i<n; i++){
        cin >> time[i].first;
        time[i].second=i;
    }
    sort(time.begin(), time.end(), customCompare);
    vector<int> solution(n, 0);
    vector<int> machine(m, 0);
    for(int i=0; i<n; i++){
        int idm=min(machine);
        solution[time[i].second]=idm;
        machine[idm]+=time[i].first;
    }
    for(auto x : solution){
        cout << x << " ";
    }
    return 0;
}