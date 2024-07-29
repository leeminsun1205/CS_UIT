#include <bits/stdc++.h>
#include <tuple>
using namespace std;
vector<vector<int>> map_game;
vector<int> X = {-1, 1, 0, 0, -1, -1, 1, 1};
vector<int> Y = {0, 0, -1, 1, -1, 1, 1, -1};
const int INF = 25e6;
void Dijkstra(int x_hSi, int y_hSi, int x_hCung, int y_hCung, int m, int n){
    vector<vector<int>> distance(m, vector<int>(n, INF));
    vector<vector<bool>> closed(m, vector<bool>(n, false));
    distance[x_hSi][y_hSi] = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> Q;
    Q.push({0, x_hSi, y_hSi});
    while(!Q.empty()){
        auto curNode = Q.top();
        int x_cur = get<1>(curNode);
        int y_cur = get<2>(curNode);
        Q.pop();
        if(x_cur==x_hCung && y_cur==y_hCung){
            cout << distance[x_cur][y_cur];
            return;
        }
        if(closed[x_cur][y_cur]==true){
            continue;
        }
        closed[x_cur][y_cur]=true;
        for(int action = 0; action < 8; action++){
            int x_new = x_cur + X[action];
            int y_new = y_cur + Y[action];
            if(0<=x_new && x_new<m && 0<=y_new  && y_new<n && map_game[x_new][y_new]==0 && closed[x_new][y_new]==false){
                if(distance[x_new][y_new]>distance[x_cur][y_cur] + 1){
                    distance[x_new][y_new] = distance[x_cur][y_cur] + 1;
                    Q.push({distance[x_new][y_new], x_new, y_new});
                }
            }
        }
    }
    cout << -1;
}
int main(){
    int m, n, x_hSi, y_hSi, x_hCung, y_hCung;
    cin >> m >> n >> x_hSi >> y_hSi >> x_hCung >> y_hCung;
    map_game = vector<vector<int>>(m, vector<int>(n, 0));
    for(int i=m-1; i>=0; i--){
        for(int j=0; j<n; j++){
            cin >> map_game[i][j];
        }
    }
    Dijkstra(x_hSi, y_hSi, x_hCung, y_hCung, m, n);
    return 0;
}