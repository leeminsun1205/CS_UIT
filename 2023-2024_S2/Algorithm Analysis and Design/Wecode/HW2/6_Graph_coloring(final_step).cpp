#include <bits/stdc++.h>
using namespace std;

map<string, set<string>> adj_list; // lưu đồ thị bằng danh sách kề
map<string, int> colors; // lưu trạng thái màu của các đỉnh
vector<string> vertexes; // lưu thứ các đỉnh theo thứ tự nhập
set<int> assignedColor; // lưu các đỉnh đã được tô màu
void input(int v, int e){
    string x, y;
    // nhập v đỉnh
    for(int i=0; i<v; i++){
        cin >> x;
        colors[x]=-1;
        vertexes.push_back(x);
    }
    // nhập e cạnh
    for(int i=0; i<e; i++){
        cin >> x >> y;
        adj_list[x].insert(y);
        adj_list[y].insert(x);
    }
//     for(auto x : adj_list){
//         cout << x.first << ": ";
//         for(auto y : x.second){
//             cout << y << ", ";
//         }
//         cout << endl;
//     }
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
bool toMau(string u){
    for(auto x : assignedColor){
        if(checkValidColor(u, x)){
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
int main(){
    int v, e;
    cin >> v >> e;
    input(v, e);
    process(v);
    return 0;
}