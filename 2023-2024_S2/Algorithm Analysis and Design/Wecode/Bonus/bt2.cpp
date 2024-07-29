/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

//###INSERT CODE HERE -
class Graph{
    vector<vector<int>> G;
    vector<string> names;
    map<string, int> mpg;

public:
    void nhap(int v, int e){
        G = vector<vector<int>>(v, vector<int>(v, 0));
        names.resize(v);
        string x, y;
        for (int i = 0; i < v; i++){
            cin >> x;
            names[i] = x;
            mpg[x] = i;
        }
        for (int i = 0; i < e; i++){
            cin >> x >> y;
            G[mpg[x]][mpg[y]] = 1;
        }
    }

    void myProcess(int n){
        int choose;
        string u, v;
        for (int i = 0; i < n; i++){
            cin >> choose;
            if (choose == 1)
            {
                cin >> u >> v;
                if (G[mpg[u]][mpg[v]] == 1)
                    cout << "TRUE" << endl;
                else
                    cout << "FALSE" << endl;
            }
            else if (choose == 2){
                cin >> u;
                vector<string> dinh_ke;
                for (int j = 0; j < names.size(); j++){
                    if (G[mpg[u]][j] == 1)
                        dinh_ke.push_back(names[j]);
                }
                if (dinh_ke.empty())
                    cout << "NONE" << endl;
                else{
                    for (const string &x : dinh_ke)
                        cout << x << " ";
                    cout << endl;
                }
            }
        }
    }
};
int main()
{
    Graph G;
    int v, e, n; cin >> v >> e >> n;
    G.nhap(v, e);
    G.myProcess(n);
    return 0;
}

