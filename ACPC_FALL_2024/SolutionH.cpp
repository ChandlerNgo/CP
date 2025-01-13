#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> grid;
    for(int i = 0; i < n; i++){
        string row;
        cin >> row;
        grid.push_back(row);
    }

    // start at corners dfs in

    queue<int> x;
    queue<int> y;
    queue<string> action;


    if(grid[0][0] == 'o' && grid[n-1][0] == 'o' && grid[0][n-1] == 'o' && grid[n-1][n-1] == 'o'){
        cout << "SKINWALKER" << endl;
        return 0;
    }

    if(grid[0][0] != 'o'){
        x.push(0);
        y.push(0);
        action.push("right");
    }
    if(grid[0][n-1] != 'o'){
        action.push("left");
    }

    while(!x.empty()){
        int curX = x.front();
        x.pop();
        int curY = y.front();
        y.pop();
        string curAction = action.front();
        action.pop();
        if(curAction == "right"){
            if(curY > 0){
                if(grid[curX][curY] == 'X'){

                        cout << "SKINWALKER" << endl;
                        return 0;
                }
                if(curX > 0){
                    if(grid[curX][curY] == 'X'){
                        cout << "SKINWALKER" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "HUMAN" << endl;
}