#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<vector<int>> adj_matrix; // ma trận kề
map<int, vector<int>> adj_list; // danh sách kề

void input(int n){
    adj_matrix = vector<vector<int>>(n, vector<int>(n)); // khởi tạo giá trị ban đầu cho ma trận kề
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> adj_matrix[i][j];
        }
    }
}
void process(int n){
    // duyệt ma trận kề
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            // nếu phần tử đó = 1 thì thêm cạnh i->j vào danh sách kề
            if (adj_matrix[i][j]==1){
                adj_list[i].push_back(j);
            }
        }
    }
    // duyệt danh sách kề
    for(auto x : adj_list){
        // nếu có tồn tại đỉnh kề với x thì xuất thông tin đỉnh kề
        if (x.second.size()!=0){
            cout << x.first + 1 << "->";
            for(auto y : x.second){
                cout << y + 1 << " ";
            }
        cout << endl;
        }
    }
}
int main(){
    int n;
    cin >> n;
    input(n);
    process(n);
    return 0;
}