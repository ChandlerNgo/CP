#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

bool checkQueens(pair<int,int> queen1, pair<int,int> queen2){
    int x1 = queen1.first;
    int y1 = queen1.second;
    int x2 = queen2.first;
    int y2 = queen2.second;

    if(x1 == x2 || y1 == y2){
        return false;
    }
    if(x1 + y1 == x2 + y2){
        return false;
    }
    if(y1-x1 == y2-x2){
        return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int,int>> queens;

    for(int i = 0; i < n; i++){
        int x;
        int y;
        cin >> x >> y;
        queens.push_back({x,y});
    }
    bool wrong = false;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(!checkQueens(queens[i],queens[j])){
                wrong = true;
                break;
            }
            checkQueens(queens[i],queens[j]);
        }
        if(wrong){
            break;
        }
    }

    if(wrong){
        cout << "INCORRECT" << endl;
    }else{
        cout << "CORRECT" << endl;
    }
}