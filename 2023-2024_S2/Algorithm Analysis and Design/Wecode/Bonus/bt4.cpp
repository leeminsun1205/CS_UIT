#include <bits/stdc++.h>
using namespace std;
class Graph{
    vector<string> names;
    map<string, set<string>> adjlist;

public:
    void input(int e){
        string x, y;
        for(int i = 0; i < e; i++){
            cin >> x >> y;
            adjlist[y];
            adjlist[x].insert(y);
        }
    }
    void process(int n){
        int c;
        for(int i = 0; i < n; i++){
            cin >> c;
            string x, y;
            if (c == 1){
                cin >> x >> y;
                set<string> s = adjlist[x];
                if (s.find(y)!=s.end())
                    cout << "TRUE" << endl;
                else
                    cout << "FALSE" << endl;
            }
            else if(c == 2){
                cin  >> x;
                int count = 0;
                if (!adjlist[x].empty()){
                    for (const string &k : adjlist[x])
                        count++;
                }
                cout << count << endl;
            }
        }
        cout << endl;
        }
};
int main(){
    Graph G;
    int e, n; 
    cin >> e >> n;
    G.input(e);
    G.process(n);
}