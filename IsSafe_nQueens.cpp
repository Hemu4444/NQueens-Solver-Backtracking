#include <iostream>
#include <vector>
using namespace std;

void PrintBoard(vector<vector<char>> board){
    int n = board.size();

    for(int i=0; i<n; i++){
        
        for(int j=0; j<n; j++){

            cout << board[i][j] << " ";
        }

        cout << endl;
    }

    cout << "---------------\n";
}

bool isSafenQueens(vector<vector<char>> board, int row, int col){

    int n = board.size();

    // horizontal safety

    for(int j=0; j<n; j++){

        if(board[row][j] == 'Q'){

            return false;
        }
    }

    //vertical  safety

    for(int i=0; i<row; i++){

        if(board[i][col] == 'Q'){

            return false;
        }

    }

    // diagonal left

    for(int i=row, j=col; i>=0 && j>=0 ;i--,j--){

        if(board[i][j] == 'Q'){

            return false;

        }
    }

    // diagonal right

    for(int i=row, j=col; i>=0 && j<n ; i--,j++){

        if(board[i][j] == 'Q'){

            return false;   
        }
    }

    return true;


}

void nQueens(vector<vector<char>> board, int row){

    int n = board.size();

    if(row == n){

        PrintBoard(board);
        return;
    }
    for(int j=0; j<n; j++){

        if(isSafenQueens(board, row, j)){

            board[row][j] = 'Q';
            nQueens(board, row+1);
            board[row][j] = '.';

        }
    }

}

int main(){

    vector<vector<char>> board;
    int n = 9;

    for(int i=0; i<n; i++){

        vector<char> newRow;

        for(int j=0; j<n; j++){

            newRow.push_back('.');
        }

        board.push_back(newRow);
        
    }

    nQueens(board, 0);


    return 0;

}
