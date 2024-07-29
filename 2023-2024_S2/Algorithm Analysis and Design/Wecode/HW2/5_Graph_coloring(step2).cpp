#include <bits/stdc++.h>
using namespace std;

map<string, set<string>> adj_list; // lưu đồ thị bằng danh sách kề
map<string, int> colors; // lưu trạng thái màu của các đỉnh
vector<string> vertexes; // lưu thứ các đỉnh theo thứ tự nhập
vector<string> vertexToPaint; // lưu các đỉnh cần xem xét
set<int> assignedColor; // lưu các đỉnh đã được tô màu
void input(int v, int e, int n){
    string x, y;
    // nhập v đỉnh
    for(int i=0; i<v; i++){
        cin >> x;
        colors[x];
        vertexes.push_back(x);
    }
    // nhập e cạnh
    for(int i=0; i<e; i++){
        cin >> x >> y;
        adj_list[x].insert(y);
        adj_list[y].insert(x);
    }
    int color;
    // nhập trạng thái màu của v đỉnh
    for(int i=0; i<v; i++){
        cin >> color;
        colors[vertexes[i]]=color;
        if (color != -1){
            assignedColor.insert(color);
        }
    }
    vertexes.clear();
    vertexes.shrink_to_fit();
    // nhập n đỉnh cần xem xét
    for(int i=0; i<n; i++){
        cin >> x;
        vertexToPaint.push_back(x);
    }
    // for(auto x : adj_list){
    //     cout << x.first << ": ";
    //     for(auto y : x.second){
    //         cout << y << ", ";
    //     }
    //     cout << endl;
    // }
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
int toMau(string u){
    if (!assignedColor.empty()){
        for(auto x : assignedColor){
            if(checkValidColor(u, x)){
                return x;
            }
        }
    }
    for(int i=0; i<16777216; i++){
        if(!checkDup(i)){
            return i;
        }
    }
}
void process(int v, int e, int n){
    for(int i=0; i<n; i++){
        if(colors[vertexToPaint[i]]!=-1){
            if(checkValidVertex(vertexToPaint[i])){
                cout << "TRUE\n";
            }
            else{
                cout << toMau(vertexToPaint[i]) << "\n";
            }
        }
        else{
            cout << toMau(vertexToPaint[i]) << "\n";
        }
    }
}
int main(){
    int v, e, n;
    cin >> v >> e >> n;
    input(v, e, n);
    process(v, e, n);
    return 0;
}