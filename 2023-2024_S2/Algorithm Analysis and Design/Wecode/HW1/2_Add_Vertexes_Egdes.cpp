#include <iostream>
#include <map>
#include <set>
using namespace std;
map<string, set<string>> adj_list; // danh sách kề
void process(){
    int option;
    cin >> option;
    string u, v;
    while(option){
        // lựa chọn 1
        if (option==1){
            cin >> v;
            // nếu không tìm thấy v trong danh sách kề thì in ra "DUP"
            if (adj_list.find(v)!=adj_list.end()){
                cout << "DUP\n";
            }
            // ngược lại thêm v vào danh sách kề và in ra "ADD"
            else{
                adj_list[v];
                cout << "ADD\n";
            }
        }
        // lựa chọn 2
        else if (option==2){
            cin >> u >> v;
            // nếu u và v đều đã có trong danh sách kề thì kiểm tra
            if (adj_list.find(u)!=adj_list.end() && adj_list.find(v)!=adj_list.end()){
                // nếu đã tồn tại 1 cạnh u->v trong danh sách kề thì in ra "DUP2"
                if (adj_list[u].find(v)!=adj_list[u].end()){
                    cout << "DUP2\n";
                }
                // ngược lại nếu không tồn tại 1 cạnh u->v thì thêm cạnh u->v vào danh sách kề và in ra "ADD3"
                else{
                    adj_list[u].insert(v);
                    cout << "ADD3\n";
                }
            }
            // ngược lại nếu u hoặc v không có trong danh sách kề
            else{
                adj_list[v]; // thêm v vào danh sách kề
                adj_list[u].insert(v); // thêm cạnh u->v vào danh sách kề
                cout << "ADD2\n"; 
            }
        }
        // lựa chọn 3
        else if (option==3){
            cin >> u >> v;
            // nếu u có trong danh sách kề và tồn tại cạnh u-> thì in ra "TRUE"
            if (adj_list.find(u)!=adj_list.end() && adj_list[u].find(v)!=adj_list[u].end()){
                cout << "TRUE\n";
            }
            // ngược lại in ra "FALSE"
            else{
                cout << "FALSE\n";
            }
        }
        // lựa chọn 4
        else{
            cin >> u;
            // nếu u có trong danh sách kề thì in râ số lượng đỉnh kề
            if (adj_list.find(u)!=adj_list.end()){
                cout << adj_list[u].size() << "\n";
            }
            // ngược lại in ra 0
            else{
                cout << 0 << "\n";
            }
        }
        cin >> option;
    }
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0); // dòng tăng tốc độ nhập xuất
    process();
    return 0;
}