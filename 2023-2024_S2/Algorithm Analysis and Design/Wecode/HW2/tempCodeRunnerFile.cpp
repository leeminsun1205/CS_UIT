
            if(!checkDup(j)){
                colors[vertexes[i]]=j;
                assignedColor.insert(j);
                if(i==v-1){
                    if(assignedColor.size()<MIN){
                        MIN=assignedColor.size();
                        // for(int i=0; i<v; i++){
                        //     store[i]=colors[vertexes[i]];
                        // }
                    }
                    for(int i=0; i<v; i++){
                        cout << colors[vertexes[i]] << " ";
                    }
                    cout << endl;
                }
                else btrack_toMau(i+1, v, store);
                colors[vertexes[i]]=-1;
            }
        }
    }
}
int main(){
    int v, e;
    cin >> v >> e;
    input(v, e);
    vector<string> store(v, " ");
    btrack_toMau(0, v, store);
    // for(auto x : store){
    //     cout << x << " ";
    // }
    return 0;
}