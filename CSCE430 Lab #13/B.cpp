#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

struct Edge{
    pair<double,double> to;
    double weight;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h,w;
    cin >> h >> w;
    vector<string> board;
    for(int i = 0; i < h; i++){
        string s;
        cin >> s;
        board.push_back(s);
    }
    set<pair<double,double>> validCoords;

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(board[i][j] == 'X'){
                validCoords.insert({i,j});
                validCoords.insert({i+1,j});
                validCoords.insert({i,j+1});
                validCoords.insert({i+1,j+1});
            }else{
                validCoords.insert({i,j});
                validCoords.insert({i+1,j});
                validCoords.insert({i,j+1});
                validCoords.insert({i+1,j+1});

                validCoords.insert({i+.5,j});
                validCoords.insert({i+.5,j+1});
                validCoords.insert({i,j+.5});
                validCoords.insert({i+1,j+.5});
            }
        }
    }

    for(auto coord : validCoords){
        double x = coord.first;
        double y = coord.second;

        if(x == ((double)(int)x) && y == ((double)(int)y)){
            cout << "square " << x << " " << y << endl;
            vector<double> dx = {1,0.5,0};
        }else{
            cout << "circle " << x << " " << y << endl;
        }
    }

    map<pair<double,double>,vector<Edge>> adj;


}