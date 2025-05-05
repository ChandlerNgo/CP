#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

struct State{
    pair<int,int> position;
    int collected;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int w;
    int h;
    cin >> w >> h;

    vector<string> board(h, "");

    for(int i = 0; i < h; i++){
        string s;
        cin >> s;
        board[i] = s;
    }

    // coords are w,h
    pair<int,int> player;

    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            if(board[j][i] == 'P'){
                player = {i,j};
            }
        }
    }

    stack<State> q;
    q.push({player, 0});

    int gold = 0;
    set<pair<int,int>> visited;

    while(!q.empty()){
        State current = q.top();
        q.pop();
        int y = current.position.second;
        int x = current.position.first;

        
        if(y < 0 || y >= h || x < 0 || x >= w || board[y][x] == '#' || board[y][x] == 'T' || visited.find({x,y}) != visited.end()){
            continue;
        }

        if(board[y][x] == 'G'){
            gold += 1;
        }
        visited.insert({x,y});


        if(board[y+1][x] == 'T' || board[y-1][x] == 'T' || board[y][x+1] == 'T' || board[y][x-1] == 'T'){
            continue;
        }


        q.push({{x+1,y}, current.collected});
        q.push({{x-1,y}, current.collected});
        q.push({{x,y-1}, current.collected});
        q.push({{x,y+1}, current.collected});
    }

    cout << gold << endl;
}