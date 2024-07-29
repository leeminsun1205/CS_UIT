#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
map<string, set<string>> adj_list;

void input(int e){
    string u, v;
    for(int i=0; i<e; i++){
        cin >> u >> v;
        adj_list[u].insert(v);
    }
}
void process(){
    int num_edges=0;
    for(auto x: adj_list){
        num_edges+=x.second.size();
    }
    int num_vertexes=adj_list.size();
    if (num_edges==num_vertexes*(num_vertexes-1)){
        cout << "TRUE";
    }
    else cout << "FALSE";
}
int main(){
    int e;
    cin >> e;
    input(e);
    process();
    return 0;
}