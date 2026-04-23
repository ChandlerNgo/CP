#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

struct DoorCount{
    int x;
    int y;
    int val;
};

struct MinDoorCount {
    bool operator()(const DoorCount& a, const DoorCount& b) {
        return a.val > b.val;
    }
};

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& val : row) {
            if (val == INT_MAX) {
                std::cout << "   "; // Print blank space for INT_MAX
            } else {
                std::cout << val << " ";
            }
        }
        std::cout << "\n";
    }
}

void bfs(vector<string>& board, vector<vector<int>>& doors, int h, int w, DoorCount start){
    set<pair<int,int>> visited;

    priority_queue<DoorCount, std::vector<DoorCount>, MinDoorCount> pq;

    pq.push(start);

    while(!pq.empty()){
        DoorCount curPos = pq.top();
        pq.pop();

        if(curPos.x < 0 || curPos.y < 0 || curPos.x >= w || curPos.y >= h || board[curPos.y][curPos.x] == '*' || visited.find({curPos.x,curPos.y}) != visited.end()){
            continue;
        }

        visited.insert({curPos.x,curPos.y});
    
        doors[curPos.y][curPos.x] = min(doors[curPos.y][curPos.x], curPos.val + (board[curPos.y][curPos.x] == '#'));
        
        pq.push({curPos.x+1, curPos.y, doors[curPos.y][curPos.x]});
        pq.push({curPos.x-1, curPos.y, doors[curPos.y][curPos.x]});
        pq.push({curPos.x, curPos.y+1, doors[curPos.y][curPos.x]});
        pq.push({curPos.x, curPos.y-1, doors[curPos.y][curPos.x]});
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int h;
        int w;
        cin >> h >> w;
        vector<string> board;
        for(int i = 0; i < h; i++){
            string s;
            cin >> s;
            board.push_back(s);
        }

        vector<DoorCount> outsidePositions;
        vector<DoorCount> prisonerPositions;

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(board[i][j] == '$'){
                    prisonerPositions.push_back({j,i,0});
                }

                if((i == 0 || i == h-1 || j == 0 || j == w-1) && board[i][j] != '*'){
                    outsidePositions.push_back({j,i,0});
                }
            }
        }

        // bfs all border , prisoners

        // if they all have a valid value
        //

        vector<vector<int>> outside(h, vector<int>(w,INT_MAX));
        vector<vector<int>> prisoner1(h, vector<int>(w,INT_MAX));
        vector<vector<int>> prisoner2(h, vector<int>(w,INT_MAX));

        for(int i = 0; i < outsidePositions.size(); i++){
            bfs(board,outside,h,w,{outsidePositions[i].x,outsidePositions[i].y,0});
        }
        
        bfs(board,prisoner1,h,w,{prisonerPositions[0].x,prisonerPositions[0].y,0});
        bfs(board,prisoner2,h,w,{prisonerPositions[1].x,prisonerPositions[1].y,0});

        ll minEscape1 = INT_MAX;
        ll minEscape2 = INT_MAX;
        ll minDoors = INT_MAX;

        // printMatrix(outside);
        // printMatrix(prisoner1);
        // printMatrix(prisoner2);

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(board[i][j] == '*'){
                    continue;
                }
                if(i == 0 || i == h-1 || j == 0 || j == w-1){ 
                    minEscape1 = min(minEscape1, (ll)prisoner1[i][j] + outside[i][j]);
                    minEscape2 = min(minEscape2, (ll)prisoner2[i][j] + outside[i][j]);
                }

                ll totalDoors = 0;
                if (outside[i][j] != INT_MAX) totalDoors += outside[i][j];
                if (prisoner1[i][j] != INT_MAX) totalDoors += prisoner1[i][j];
                if (prisoner2[i][j] != INT_MAX) totalDoors += prisoner2[i][j];

                if (outside[i][j] == INT_MAX || prisoner1[i][j] == INT_MAX || prisoner2[i][j] == INT_MAX) {
                    totalDoors = INT_MAX;
                }

                if (board[i][j] == '#') {
                    totalDoors = (totalDoors == INT_MAX) ? INT_MAX : totalDoors - 2;
                }

                minDoors = min(minDoors, totalDoors);
            }
        }



        // cout << minDoors << " " << minEscape1+minEscape2 << "\n";
        cout << min(minDoors, minEscape1+minEscape2) << endl;
        // print min of prisoners going on their own vs combined meeting location
    }
    cout << flush;
}