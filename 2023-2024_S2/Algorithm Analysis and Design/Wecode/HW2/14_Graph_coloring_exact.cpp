#include <bits/stdc++.h>
using namespace std;

map<string, set<string>> adj_list; 
map<string, int> colors; 
vector<string> vertexes; 
set<int> assignedColor; 
void input(int v, int e){
    string x, y;
    for(int i=0; i<v; i++){
        cin >> x;
        colors[x]=-1;
        vertexes.push_back(x);
    }
    for(int i=0; i<e; i++){
        cin >> x >> y;
        adj_list[x].insert(y);
        adj_list[y].insert(x);
    }
}
// kiểm tra đỉnh có màu sắc hợp lệ hay chưa
bool checkValidVertex(string u){
    for(auto x: adj_list[u]){
        if(colors[u] == colors[x]){
            return 0;
        }
    }
    return 1;
}
// kiểm tra xem màu sắc được chọn tô có hợp lệ hay chưa
bool checkValidColor(string u, int color){
    for(auto x: adj_list[u]){
        if(color == colors[x]){
            return 0;
        }
    }
    return 1;
}
// kiểm tra màu sắc trùng với tập màu đã tô hay không
bool checkDup(int color){
    for(auto x : assignedColor){
        if (color == x){
            return 1;
        } 
    }
    return 0;
}
void toMau(string u){
    for(auto x : assignedColor){
        if(checkValidColor(u, x)){
            colors[u]=x;
            assignedColor.insert(x);
            return;
        }
    }
    for(int i=0; i<16777216; i++){
        if(!checkDup(i)){
            colors[u]=i;
            assignedColor.insert(i);
            return;
        }
    }
}
void process(int v){
    for(int i=0; i<v; i++){
        toMau(vertexes[i]);
    }
    for(int i=0; i<v; i++){
        cout << colors[vertexes[i]] << " ";
    }
}
bool checkToMau(int v){
    for(int i=0; i<v; i++){
        if (!checkValidVertex(vertexes[i])){
            return false;
        }
    }
    return true;
}
void btrack_toMau(int i, int v, vector<int> solution){
    for(int j=0; j<v; j++){
        solution.push_back(j);
        colors[vertexes[i]]=j;
        if(i==v-1 && checkToMau(v)){
            for(int i=0; i<v; i++){
                cout << solution[i] << " ";
            }
            cout << endl;
        }
        else btrack_toMau(i+1, v, solution);
        colors[vertexes[i]]=-1;
        solution.pop_back();
    }
}
int main(){
    int v, e;
    cin >> v >> e;
    input(v, e);
    // process(v);
    vector<int> solution;
    btrack_toMau(0, v, solution);
    return 0;
}