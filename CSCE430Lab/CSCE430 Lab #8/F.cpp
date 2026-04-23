#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int y;
    int x;
    cin >> y >> x;
    vector<string> board;
    for(int i = 0; i < y; i++){
        string s;
        cin >> s;
        board.push_back(s);
    }

    int loops = 0;

    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            if(board[i][j] == '#'){
                loops += 1;
                queue<pair<int,int>> q;
                q.push({i,j});
                while(!q.empty()){
                    pair<int,int> coord = q.front();
                    q.pop();
        
                    if(coord.first < 0 || coord.second < 0 || coord.first >= y || coord.second >= x || board[coord.first][coord.second] == '.'){
                        continue;
                    }
        
        
                    board[coord.first][coord.second] = '.';
        
                    q.push({coord.first+1,coord.second+1});
                    q.push({coord.first+1,coord.second});
                    q.push({coord.first+1,coord.second-1});
                    q.push({coord.first,coord.second+1});
                    q.push({coord.first,coord.second-1});
                    q.push({coord.first-1,coord.second+1});
                    q.push({coord.first-1,coord.second});
                    q.push({coord.first-1,coord.second-1});
                }
            }
        }
    }
    cout << loops << endl;
}