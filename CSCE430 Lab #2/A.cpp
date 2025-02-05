#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // 0 1 2 3 left up right down
    vector<vector<int>> board(4,vector<int>(4,0));
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            int num;
            cin >> num;
            board[i][j] = num;
        }
    }

    int direction;
    cin >> direction;

    if(direction == 0){
        for(int i = 0; i < 4; i++){
            vector<int> row;

            for(int j = 0; j < 4; j++){
                if(board[i][j] != 0){
                    row.push_back(board[i][j]);
                }
            }

            // merge, if merged go to next index
            vector<int> mergedRow;
            for(int j = 0; j < row.size(); j++){
                if(row[j] == row[j+1]){
                    mergedRow.push_back(row[j]*2);
                    j += 1;
                }else{
                    mergedRow.push_back(row[j]);
                }
            }

            while(mergedRow.size() != 4){
                mergedRow.push_back(0);
            }
            board[i] = mergedRow;
        }
    }else if(direction == 1){
        for(int i = 0; i < 4; i++){
            vector<int> row;

            for(int j = 0; j < 4; j++){
                if(board[j][i] != 0){
                    row.push_back(board[j][i]);
                }
            }

            // merge, if merged go to next index
            vector<int> mergedRow;
            for(int j = 0; j < row.size(); j++){
                if(row[j] == row[j+1]){
                    mergedRow.push_back(row[j]*2);
                    j += 1;
                }else{
                    mergedRow.push_back(row[j]);
                }
            }

            while(mergedRow.size() != 4){
                mergedRow.push_back(0);
            }

            for(int j = 0; j < 4; j++){
                board[j][i] = mergedRow[j];
            }
        }
    }else if(direction == 2){
        for(int i = 0; i < 4; i++){
            vector<int> row;

            for(int j = 3; j >= 0; j--){
                if(board[i][j] != 0){
                    row.push_back(board[i][j]);
                }
            }

            // merge, if merged go to next index
            vector<int> mergedRow;
            for(int j = 0; j < row.size(); j++){
                if(row[j] == row[j+1]){
                    mergedRow.push_back(row[j]*2);
                    j += 1;
                }else{
                    mergedRow.push_back(row[j]);
                }
            }


            while(mergedRow.size() != 4){
                mergedRow.push_back(0);
            }

            for(int j = 0; j < 4; j++){
                board[i][j] = mergedRow[3-j];
            }
        }
    }else{
        for(int i = 0; i < 4; i++){
            vector<int> row;

            for(int j = 3; j >= 0; j--){
                if(board[j][i] != 0){
                    row.push_back(board[j][i]);
                }
            }

            // merge, if merged go to next index
            vector<int> mergedRow;
            for(int j = 0; j < row.size(); j++){
                if(row[j] == row[j+1]){
                    mergedRow.push_back(row[j]*2);
                    j += 1;
                }else{
                    mergedRow.push_back(row[j]);
                }
            }

            while(mergedRow.size() != 4){
                mergedRow.push_back(0);
            }

            for(int j = 3; j >= 0; j--){
                board[3-j][i] = mergedRow[j];
            }
        }
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(j != 3){
                cout << board[i][j] << " ";
            }else{
                cout << board[i][j];
            }
        }
        cout << endl;
    }
}