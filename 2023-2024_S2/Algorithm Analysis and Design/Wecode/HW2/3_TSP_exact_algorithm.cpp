#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <climits>
using namespace std; 
map<string, map<string, long long>> adj_list;
long long Min = LLONG_MAX;
void input(int e){
    string u, i; 
    for(int k=0; k<e; k++){
        cin >> u >> i;
        cin >> adj_list[u][i];
    }
}
void TSP(int i, int n, string s, string u, vector<string> solution, set<string> closed, vector<string> &store){
    if (i==0){
        solution.push_back(s);
        closed.insert(s);
        TSP(i+1, n, s, s, solution, closed, store);
        closed.erase(s);
        solution.pop_back();
    }
    else if(i>0 && i<n){
        if(!adj_list[u].empty()){
            for(auto x : adj_list[u]){
                if(closed.find(x.first)==closed.end()){
                    solution.push_back(x.first);
                    closed.insert(x.first);
                    TSP(i+1, n, s, x.first, solution, closed, store);
                    closed.erase(x.first);
                    solution.pop_back();
                }
            }
        }
    }
    else if (i==n){
        if(adj_list[u].find(s)!=adj_list[u].end()){
            solution.push_back(s);
            closed.insert(s);
            long long sum=0;
            for(int i=0; i<solution.size()-1; i++){
                sum+=adj_list[solution[i]][solution[i+1]];
            }
            if(sum < Min){
                Min = sum;
                for(int i=0; i<solution.size(); i++){
                    store[i]=solution[i];
                }
            }
            closed.erase(s);
            solution.pop_back();
        }
    }
}
int main(){
    int e;
    string s;
    cin >> e;
    cin >> s;
    input(e);
    vector<string> solution;
    vector<string>store(adj_list.size()+1, "");
    set<string> closed;
    TSP(0, adj_list.size(), s, s, solution, closed, store);
    for(auto x : store){
        cout << x << " ";
    }
    return 0;
}