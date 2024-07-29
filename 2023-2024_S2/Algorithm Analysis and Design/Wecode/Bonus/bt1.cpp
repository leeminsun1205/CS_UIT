/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include<iostream>
#include<vector>
using namespace std;

//###INSERT CODE HERE -
void inputGraph(vector<vector<int>> &G, int v, int e){
    G = vector<vector<int>>(v, vector<int>(v,0)); // Cap phat vung nho cho ma tran va khoi tao ma tran toan 0
    for(int i=0; i<e; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        G[x][y]=1;
    }
}
void outputGraph(vector<vector<int>> G, int v){
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
}
void process(vector<vector<int>> G, int v, int n){
    for(int i=0; i<n; i++){
        int choose;
        cin >> choose;
        if (choose == 1){
            int u, i;
            cin >> u >> i;
            u--; i--;
            if(G[u][i]==1){
                cout << "TRUE";
            }
            else cout << "FALSE";
        }
        else{
            int u;
            cin >> u;
            u--;
            int count = 0;
            for(int i=0; i<v; i++){
                if(G[u][i]==1){
                    cout << i + 1<< " ";
                    count++;
                }
            }
            if (count == 0) cout << "NONE";
        }
        cout << endl;
    }
}

int main()
{
	int v, e, n;
	cin >> v >> e >> n; //v: số đỉnh, e: số cạnh, n: số thao tác
	vector<vector<int> > G;
	inputGraph(G,v,e);
    // outputGraph(G,v);
    process(G,v,n);
	return 0;
}
