#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> board;
    int r; int c;
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        string s;
        cin >> s;
        board.push_back(s);
    }

    for(int i = 0; i < c; i++){
        // read until #
        // then copy apples and fill in with dots
        string currentRow = "";
        int apples = 0;
        for(int j = r-1; j >= 0; j--){
            if(board[j][i] == 'a'){
                apples += 1;
            }else if(board[j][i] == '#'){
                while(currentRow.size() != ((r-1) - j)){
                    if(apples > 0){
                        currentRow += 'a';
                        apples -= 1;
                    }else{
                        currentRow += '.';
                    }
                }
                currentRow += '#';
            }
        }
        while(currentRow.size() != r){
            if(apples > 0){
                currentRow += 'a';
                apples -= 1;
            }else{
                currentRow += '.';
            }
        }
        // cout << "this is current row: " << currentRow << endl;
        for(int k = r-1; k >= 0; k--){
            board[k][i] = currentRow[r-1-k];
        }
        currentRow = "";
        apples = 0;
    }
    for(int i = 0; i < board.size(); i++){
        cout << board[i] << endl;
    }
}