#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int m;
    cin >> n >> m;
    vector<string> board;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        board.push_back(s);
    }

    vector<vector<int>> answer(n+2,vector<int>(m+2,0));

    for(int x = 0; x < 200; x++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(board[i-1][j-1] != '.'){
                    answer[i][j] = 1 + min({answer[i+1][j],answer[i-1][j],answer[i][j+1],answer[i][j-1]});
                }
            }
        }
    }

    int maxRing = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            maxRing = max(maxRing, answer[i][j]);
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << ((maxRing < 10) ? "." : "..")  << ((answer[i][j] == 0) ? "." : to_string(answer[i][j]));
        }
        cout << endl;
    }
}