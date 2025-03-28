#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

struct State{
    int x;
    int y;
    int passes;
    int pathSum;
};

struct CompareState {
    bool operator()(const State& a, const State& b) {
        return a.pathSum > b.pathSum;
    }
};


vector<vector<bool>> findPasses(int r, int c, vector<vector<int>> board){
    vector<vector<bool>> passes(r,vector<bool>(c, false));
    for(int i = 1; i < r-1; i++){
        for(int j = 1; j < c-1; j++){
            if(board[i][j] > board[i][j+1] && board[i][j] > board[i][j-1] && board[i][j] < board[i+1][j] && board[i][j] < board[i-1][j]){
                passes[i][j] = true;
            }
        }
    }
    return passes;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r, c, n;
    cin >> r >> c >> n;
    
    vector<vector<int>> board(r,vector<int>(c));
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> board[i][j];
        }
    }
    
    vector<vector<bool>> passes = findPasses(r,c,board);
    
    int minPath = INT_MAX;
    priority_queue<State, vector<State>, CompareState> pq;
    for(int i = 0; i < r; i++){
        pq.push({0,i,0,0});
    }

    while(!pq.empty()){
        State cur = pq.top();
        pq.pop();

        if(cur.x >= c && cur.passes == n){
            minPath = min(minPath,cur.pathSum);
            break;
        }

        if(cur.x < 0 || cur.y < 0 || cur.x >= c || cur.y >= r || board[cur.y][cur.x] == -1){
            continue;
        }


        pq.push({cur.x+1,cur.y+1,cur.passes + passes[cur.y][cur.x], cur.pathSum + board[cur.y][cur.x]});
        pq.push({cur.x+1,cur.y,cur.passes + passes[cur.y][cur.x], cur.pathSum + board[cur.y][cur.x]});
        pq.push({cur.x+1,cur.y-1,cur.passes + passes[cur.y][cur.x], cur.pathSum + board[cur.y][cur.x]});
    }

    if(minPath == INT_MAX){
        cout << "impossible" << endl;
    }else{
        cout << minPath << endl;
    }
}