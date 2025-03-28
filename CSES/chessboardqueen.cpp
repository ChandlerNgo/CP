#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

struct Board{
    vector<string> board;
    int row;
};

bool diagonals(vector<string>& board, int r, int c, int rowInc, int colInc){
    int r1 = r;
    int c1 = c;
    while(r1 >= 0 && r1 < 8 && c1 >= 0 && c1 < 8){
        if(board[r1][c1] == 'Q'){
            return false;
        }
        r1 += rowInc;
        c1 += colInc;
    }
    return true;
}

bool isValidSquare(vector<string>& board, int r, int c){
    if(board[r][c] == '*'){
        return false;
    }
    for(int i = 0; i < 8; i++){
        if(board[r][i] == 'Q'){
            return false;
        }

        if(board[i][c] == 'Q'){
            return false;
        }
    }

    if(!diagonals(board, r, c, 1, 1)){
        return false;
    }
    if(!diagonals(board, r, c, -1, 1)){
        return false;
    }
    if(!diagonals(board, r, c, 1, -1)){
        return false;
    }
    if(!diagonals(board, r, c, -1, -1)){
        return false;
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> board(8,"");

    for(int i = 0; i < 8; i++){
        cin >> board[i];
    }

    queue<Board> q;
    q.push({board,0});
    int ways = 0;
    while(!q.empty()){
        Board cur = q.front();
        q.pop();
        int r = cur.row;
        if(r == 8){
            ways += 1;
            continue;
        }
        for(int c = 0; c < 8; c++){
            if(isValidSquare(cur.board,r,c)){
                cur.board[r][c] = 'Q';
                q.push({cur.board, r+1});
                cur.board[r][c] = '.';
            }
        }
    }
    cout << ways << endl;
}