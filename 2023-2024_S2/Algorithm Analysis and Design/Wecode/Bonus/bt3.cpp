#include <bits/stdc++.h>
using namespace std;
class Graph{
    vector<string> names;
    map<string, map<string, int>> adj;

public:
    void input(int e){
        string x, y; int z;
        for(int i = 0; i < e; i++){
            cin >> x >> y >> z;
            adj[y];
            adj[x][y] = z;
        }
    }
    void process(int n){
        for(int i=0; i<n; i++){
            vector<string> road;
            string v;
            cin >> v;
            while(v != "."){
                road.push_back(v);
                cin >> v;
            }
            int total = 0;
            bool check = 0;
            for(int j=0; j< road.size()-1; j++){
                string x = road[j];
                string y = road[j+1];
                if (adj[x].find(y)==adj[x].end()){
                    cout << "FALSE" << endl;
                    check = 1;
                    break;
                }
                total += adj[x][y];
            }
            if (check == 0) cout << total << endl;
        }
    }
};
int main(){
    Graph G;
    int e, n; 
    cin >> e >> n;
    G.input(e);
    G.process(n);
}