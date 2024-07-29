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
bool checkDup(int color){
    for(auto x : assignedColor){
        if (color == x){
            return 1;
        } 
    }
    return 0;
}
bool checkValidColor(string u, int color){
    for(auto x: adj_list[u]){
        if(color == colors[x]){
            return 0;
        }
    }
    return 1;
}

int MIN=1e9;
void btrack_toMau(int i, int v, vector<int> &store){
    if(i==0){
        colors[vertexes[i]]=0;
        assignedColor.insert(0);
        btrack_toMau(i+1, v, store);
        colors[vertexes[i]]=-1;
    }
    else if(i > 0){
        if(assignedColor.size()<MIN){
            for(auto x : assignedColor){
                if(checkValidColor(vertexes[i], x)){
                    colors[vertexes[i]]=x;
                    assignedColor.insert(x);
                    if(i==v-1){
                        if(assignedColor.size()<MIN){
                            MIN=assignedColor.size();
                            for(int i=0; i<v; i++){
                                store[i]=colors[vertexes[i]];
                            }
                        }
                    }
                    else btrack_toMau(i+1, v, store);
                    colors[vertexes[i]]=-1;
                }
            }
            for(int j=0; j<v; j++){
                if(!checkDup(j)){
                    colors[vertexes[i]]=j;
                    assignedColor.insert(j);
                    if(i==v-1){
                        if(assignedColor.size()<MIN){
                            MIN=assignedColor.size();
                            for(int i=0; i<v; i++){
                                store[i]=colors[vertexes[i]];
                            }
                        }
                    }
                    else btrack_toMau(i+1, v, store);
                    assignedColor.erase(j);
                    colors[vertexes[i]]=-1;
                }
            }
        }
    }
}
int main(){
    int v, e;
    cin >> v >> e;
    input(v, e);
    vector<int> store(v, -1);
    btrack_toMau(0, v, store);
    for(auto x : store){
        cout << x << " ";
    }
    return 0;
}