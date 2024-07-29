#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;
map<string, int> degree;
vector<string> vertexes;
map<string, set<string>> adj_list;

void input(int v, int e){
    string vertex;
    for(int i=0; i<v; i++){
        cin >> vertex;
        degree[vertex];
        vertexes.push_back(vertex);
    }
    string x, y;
    for(int i=0; i<e; i++){
        cin >> x >> y;
        adj_list[x].insert(y);
        adj_list[y].insert(x);
    }
}
void process(){

    for(auto x : degree){
        degree[x.first]=adj_list[x.first].size();
    }
    for(int i=0; i<vertexes.size(); i++){
        cout << degree[vertexes[i]] << " ";
    }
}
int main(){
    int v, e;
    cin >> v >> e;
    input(v, e);
    process();
    return 0;
}