else if (n==-1){
            int count=0;
            cout << "[";
            while (it != lst.end()){
                cout << *it;
                if (count != lst.size()-1) cout << ",";
                it++;
                count++;
            }
            cout << "]";
            break;
        }