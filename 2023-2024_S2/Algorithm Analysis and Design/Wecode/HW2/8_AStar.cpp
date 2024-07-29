#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> vertexes;
map<string, int> mpg;
vector<int> heuristic;
vector<vector<int>> adj_matrix;
const int INF = 1e9;
void input(int v, int e){
    string u, k;
    for(int i=0; i<v; i++){
        cin >> u;
        vertexes.push_back(u);
        mpg[u] = i;
    }
    int h;
    for(int i=0; i<v; i++){
        cin >> h;
        heuristic.push_back(h);
    }
    adj_matrix= vector<vector<int>>(v, vector<int>(v, 0));
    for(int i=0; i<e; i++){
        cin >> u >> k;
        cin >> adj_matrix[mpg[u]][mpg[k]];
    }
}
void update(int f, int c, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& Q){
    vector<pair<int, int>> temp;
    while (!Q.empty()) {
        if (Q.top().second != c) {
            temp.push_back(Q.top());
        }
        Q.pop();
    }
    temp.push_back({f, c});
    for(auto& p : temp) {
        Q.push(p);
    }
}
void aStar(int v, string s, string u){
    int i = mpg[s], f = mpg[u];
    vector<int> f_aStar(v, INF);
    vector<int> distance(v, INF);
    vector<int> previous(v, -1);
    vector<bool> closed(v, false);
    vector<bool> open(v, false);
    distance[i] = 0;
    int expand = 0;
    f_aStar[i] = heuristic[i];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push({f_aStar[i], i});
    while(!Q.empty()){
        int b = Q.top().second;
        Q.pop();
        ++expand;
        if (b==f) break;
        open[b]=false;
        closed[b]=true;
        for(int c=0; c< adj_matrix[b].size(); c++){
            if(adj_matrix[b][c]!=0){
                int w = adj_matrix[b][c];
                if(!open[c] && !closed[c]){
                    distance[c] = distance[b] + w;
                    f_aStar[c] = distance[c] + heuristic[c];
                    previous[c] = b;
                    Q.push({f_aStar[c], c});
                    open[c]=true;
                }
                else if(open[c]){
                    if(distance[c]>distance[b] + w){
                        distance[c] = distance[b] + w;
                        f_aStar[c] = distance[c] + heuristic[c];
                        previous[c] = b;
                        update(f_aStar[c], c, Q);
                    }
                }
                else if(closed[c]){
                    if(distance[c]>distance[b] + w){
                        closed[c]=false;
                        --expand;
                        distance[c] = distance[b] + w;
                        f_aStar[c] = distance[c] + heuristic[c];
                        previous[c] = b;
                        Q.push({f_aStar[c], c});
                        open[c]=true;
                    }
                }
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
int main(){
    int v, e;
    cin >> v >> e;
    string s, u;
    cin >> s >> u;
    input(v, e);
    aStar(v, s, u);
    return 0;
}