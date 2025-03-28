#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;


struct Coord{
    int x;
    int y;
    int depth;
};

class Compare {
    public:
        bool operator()(Coord a, Coord b)
        {
            return a.depth > b.depth;
        }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r;
    int c;
    cin >> r >> c;
    vector<vector<int>> board(r, vector<int>(c,0));
    vector<vector<int>> maxDepth(r, vector<int>(c,INT_MIN));
    priority_queue<Coord,vector<Coord>, Compare> pq;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> board[i][j];
            if(j == 0){
                pq.push({j,i,INT_MIN});
            }
        }
    }

    set<pair<int,int>> visited;

    int minDistance = INT_MAX;

    while(!pq.empty()){
        Coord cur = pq.top();
        pq.pop();

        if(cur.x == c){
            minDistance = cur.depth;
            break;
        }

        if(cur.x < 0 || cur.y < 0 || cur.x >= c || cur.y >= r || visited.find({cur.x,cur.y}) != visited.end()){
            continue;
        }

        visited.insert({cur.x,cur.y});
        maxDepth[cur.y][cur.x] = max(cur.depth, board[cur.y][cur.x]);

        pq.push({cur.x+1,cur.y,maxDepth[cur.y][cur.x]});
        pq.push({cur.x-1,cur.y,maxDepth[cur.y][cur.x]});
        pq.push({cur.x,cur.y+1,maxDepth[cur.y][cur.x]});
        pq.push({cur.x,cur.y-1,maxDepth[cur.y][cur.x]});
    }

    cout << minDistance << endl;
}