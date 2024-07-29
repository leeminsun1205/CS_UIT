#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
map<int, map<int, int>> adj_list;
vector<string> vertexes;
map<string, int> mpg;
const int INF = 1e9;
void input(int v){
    string u;
    for(int i=0; i<v; i++){
        cin >> u;
        vertexes.push_back(u);
        mpg[u]=i;
    }
    int w;
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            cin >> w;
            if(w!=0){
                adj_list[i][j]=w;
            }
        }
    }
}
struct Compare {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const{
        if (a.first == b.first) {
            return a.second < b.second;  
        }
        return a.first > b.first;  
    }
};
void Dijkstra(string s, string u, int v){
    int i=mpg[s], f=mpg[u];
    vector<int> distance(v, INF);
    vector<int> previous(v, -1);
    distance[i] = 0;
    int expand=0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> Q;
    Q.push({0, mpg[s]});
    while(!Q.empty()){
        int b=Q.top().second;
        int dis=Q.top().first;
        Q.pop();
        if (dis > distance[b])
            continue;
        ++expand;
        if (b==f){
            break;
        }
        for(auto x : adj_list[b]){
            int c = x.first;
            int w = x.second;
            if(distance[c]>distance[b] + w){
                distance[c] = distance[b] + w;
                Q.push({distance[c], c});
                previous[c] = b;
            }
        }
    }
    vector<int> path;
    int t = f;
    if(distance[mpg[u]]==INF){
        cout << "-unreachable-\n";
        cout << expand << " " << 0 << "\n";
    }
    else{
        while(1){
            path.push_back(f);
            if (f == i) break;
            f = previous[f];
        }
        for(int i=path.size()-1; i>=0; i--){
            cout << vertexes[path[i]] << " ";
        }
        cout << "\n" << expand << " " << distance[t] << "\n";
    }
}
void process(int v, int n){
    string x, y;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        Dijkstra(x, y, v);
    }
}
int main(){
    int v, n;
    cin >> v >> n;
    input(v);
    process(v, n);
    return 0;
}