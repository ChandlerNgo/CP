#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

struct State{
    bool isPerson;
    vector<string> board;
    int steps;
};

bool OOB(int nr, int nc, int r, int c){
    if(nr < 0 || nc < 0 || nr >= r || nc >= c){
        return true;
    }else{
        return false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r;
    int c;
    cin >> r >> c;
    vector<string> board;
    for(int i = 0; i < r; i++){
        string s;
        cin >> s;
        board.push_back(s);
    }

    queue<State> bfs;

    bfs.push({true, board, 0});

    // bfs:
    while(!bfs.empty()){
        State state = bfs.front();
        bfs.pop();

        if(state.isPerson){
            // person
            
            // find person
            vector<string> newBoard = state.board;
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    if(state.board[i][j] == 'J'){
                        newBoard[i][j] = '.';

                        if(OOB(i+1,j,r,c)){
                            cout << state.steps + 1 << endl;
                            return 0;
                        }
                        if(OOB(i-1,j,r,c)){
                            cout << state.steps + 1 << endl;
                            return 0;
                        }
                        if(OOB(i,j+1,r,c)){
                            cout << state.steps + 1 << endl;
                            return 0;
                        }
                        if(OOB(i,j-1,r,c)){
                            cout << state.steps + 1 << endl;
                            return 0;
                        }

                        if(newBoard[i+1][j] == '.'){
                            newBoard[i+1][j] = 'J';
                            bfs.push({0,newBoard,state.steps + 1});
                            newBoard[i+1][j] = '.';
                        }
                        if(newBoard[i-1][j] == '.'){
                            newBoard[i-1][j] = 'J';
                            bfs.push({0,newBoard,state.steps + 1});
                            newBoard[i-1][j] = '.';
                        }
                        if(newBoard[i][j+1] == '.'){
                            newBoard[i][j+1] = 'J';
                            bfs.push({0,newBoard,state.steps + 1});
                            newBoard[i][j+1] = '.';
                        }
                        if(newBoard[i][j-1] == '.'){
                            newBoard[i][j-1] = 'J';
                            bfs.push({0,newBoard,state.steps + 1});
                            newBoard[i][j-1] = '.';
                        }
                    }
                }
            }
            // add new states
        }else{
            // fire
            vector<string> newBoard = state.board;
            bool dead = false;
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    if(state.board[i][j] == 'F'){
                        
                        if(!OOB(i+1,j,r,c)){
                            if(newBoard[i+1][j] == 'J'){
                                dead = true;
                            }
                            
                            newBoard[i+1][j] = 'F';
                        }

                        if(!OOB(i-1,j,r,c)){
                            if(newBoard[i-1][j] == 'J'){
                                dead = true;
                            }
                            newBoard[i-1][j] = 'F';
                        }

                        if(!OOB(i,j+1,r,c)){
                            if(newBoard[i][j+1] == 'J'){
                                dead = true;
                            }
                            newBoard[i][j+1] = 'F';
                        }

                        if(!OOB(i,j-1,r,c)){
                            if(newBoard[i][j-1] == 'J'){
                                dead = true;
                            }
                            newBoard[i][j-1] = 'F';
                        }
                    }
                }
                if(dead){
                    break;
                }
            }
            if(!dead){
                bfs.push({1,newBoard, state.steps});
            }
        }
    }
    cout << "IMPOSSIBLE"
}