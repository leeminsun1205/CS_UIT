#include <bits/stdc++.h>
using namespace std;
vector<char> num = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
bool CheckValid(char x, int i, int j, vector<vector<char>> sudoku_board){
    for (int k = 0; k < 9; k++) {
        if (sudoku_board[i][k] == x || sudoku_board[k][j] == x)
            return false;
    }
    int row = i / 3 * 3;
    int col = j / 3 * 3;
    for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
            if (sudoku_board[row + k][col + l] == x)
                return false;
        }
    }
    return true;
}
bool stop=false;
bool ValidSudoku(vector<vector<char>> sudoku_board){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){

        }
    }
}
void Sudoku(int c, int n, int i_cur, vector<vector<char>> sudoku_board){
    if(stop==true) return;
    for(int i=i_cur; i<9; i++){
        for(int j=0; j<9; j++){
            if(sudoku_board[i][j]=='X'){
                // cout << "i:" << i << " j:" << j << " ";
                // if(i==8) stop=true;
                int i_next=i;
                for(auto x : num){
                    if(CheckValid(x, i, j, sudoku_board)){
                        // cout << x << " ";
                        // cout << endl;
                        sudoku_board[i][j] = x;
                        if(c==n){
                            stop=true;
                            for(int k=0; k<9; k++){
                                for(int l=0; l<9; l++){
                                    cout << sudoku_board[k][l] << " ";
                                }
                                cout << endl;
                            }
                            return;
                        }
                        else{
                            Sudoku(c+1, n, i_next, sudoku_board);
                        }
                        sudoku_board[i][j] = 'X';
                    }
                }
            }
            
        }
    }
}
int main(){
    int n=0;
    vector<vector<char>> sudoku_board(9, vector<char>(9, ' '));
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> sudoku_board[i][j];
            if(sudoku_board[i][j]=='X')
                n++;
        }
    }
    cout << endl;
    if(n==0){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << sudoku_board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else{
        Sudoku(1, n, 0, sudoku_board);
    }
    return 0;
}