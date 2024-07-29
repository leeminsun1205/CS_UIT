#include <iostream>
#include <map>
#include <vector>
using namespace std; 
vector<string> solution;
vector<string> store;
map<string, map<string, int>> adj_list;
void input(int e){
    string u, i; 
    int x;
    for(int k=0; k<e; k++){
        cin >> u >> i >> x;
        adj_list[u][i]=x;
    }
}
void process(string s){
    
    for(auto x : adj_list){
        if (x.first != s){
            store.push_back(x.first);
        }
    }
    solution.push_back(s);
    string current=s;
    while(!store.empty()){
        int min = 0;
        for(int i=1; i<store.size(); i++){
            if (adj_list[current][store[i]] < adj_list[current][store[min]]){
                min=i;
            }
        }
        solution.push_back(store[min]);
        current=store[min];
        store.erase(store.begin() + min);
    }
    solution.push_back(s);
    for(auto x: solution){
        cout << x << " ";
    }
}
int main(){
    int e;
    string s;
    cin >> e;
    cin >> s;
    input(e);
    process(s);
    return 0;
}