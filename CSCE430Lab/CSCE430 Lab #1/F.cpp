#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = ceil(sqrt(s.size()));
        int M = ceil(sqrt(s.size())) * ceil(sqrt(s.size()));
        while(s.size() != M){
            s += '*';
        }
        vector<string> board;
        for(int i = 0; i < n; i++){
            string cur = "";
            for(int j = 0; j < n; j++){
                cur += s[(i*n + j)];
            }
            board.push_back(cur);
        }
        for(int i = 0; i < n; i++){
            for(int j = n-1; j >= 0; j--){
                if(board[j][i] != '*'){
                    cout << board[j][i];
                }
            }
        }
        cout << endl;
    }
}