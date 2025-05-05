#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int bfs(vector<vector<int>>& board){
    set<pair<int,int>> visited;

    int regions = 0;

    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            if(visited.find({i,j}) == visited.end() && !board[i][j]){
                regions += 1;
                queue<pair<int,int>> q;
                q.push({i,j});

                while(!q.empty()){
                    pair<int,int> cur = q.front();
                    q.pop();
                    
                    if(visited.find(cur) != visited.end() || cur.first < 0 || cur.second < 0 || cur.first >= board.size() || cur.second >= board[0].size() || board[cur.first][cur.second] == 1){
                        continue;
                    }


                    visited.insert(cur);

                    q.push({cur.first+1,cur.second});
                    q.push({cur.first-1,cur.second});
                    q.push({cur.first,cur.second+1});
                    q.push({cur.first,cur.second-1});
                }
            }
        }
    }
    
    return regions;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int m;
    int q;
    cin >> n >> m >> q;

    vector<vector<int>> board(m, vector<int>(n,0));

    for(int i = 0; i < q; i++){
        int x1;
        int x2;
        int y1;
        int y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for(int j = x1-1; j < x2; j++){
            for(int k = y1-1; k < y2; k++){
                board[k][j] = 1;
            }
        }

        // for(auto row : board){
        //     for(auto x : row){
        //         cout << x << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        cout << bfs(board) << endl;
    }
}