#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> board;
    for(int i = 0; i < n; i++){
        string row;
        cin >> row;
        board.push_back(row);
    }
    bool solutionFound = false;
    queue<pair<int,int>> bfs;
    set<pair<int,int>> visited;
    for(int i = 0; i < 3; i++){
        if(board[n-1][i] == '.'){
            bfs.push({n-1,i});
        }
    }
    while(!bfs.empty()){
        pair<int,int> coords = bfs.front();
        bfs.pop();
        if(coords.first == 0){
            solutionFound = true;
            break;
        }
        if(coords.second < 0 || coords.second > 2){
            continue;
        }
        if(visited.find({coords.first,coords.second}) == visited.end()){
            if(board[coords.first][coords.second] == '.'){
                if(coords.second-1 >= 0 && coords.second-1 <= 2 && board[coords.first][coords.second-1] == '.'){
                    bfs.push({coords.first,coords.second-1});
                }
                if(coords.second+1 >= 0 && coords.second+1 <= 2 && board[coords.first][coords.second+1] == '.'){
                    bfs.push({coords.first,coords.second+1});
                }
                if(board[coords.first-1][coords.second] == '.' || board[coords.first-1][coords.second] == '/'){
                    bfs.push({coords.first-1,coords.second});
                }
            }else if(board[coords.first][coords.second] == '/'){
                if(board[coords.first-1][coords.second] == '*'){
                    bfs.push({coords.first-1,coords.second});
                }
            }else{
                if(coords.second-1 >= 0 && coords.second-1 <= 2 && board[coords.first][coords.second-1] == '*'){
                    bfs.push({coords.first,coords.second-1});
                }
                if(coords.second+1 >= 0 && coords.second+1 <= 2 && board[coords.first][coords.second+1] == '*'){
                    bfs.push({coords.first,coords.second+1});
                }
                bfs.push({coords.first-1,coords.second});
            }
        }
        visited.insert({coords.first,coords.second});

    }
    if(solutionFound){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}