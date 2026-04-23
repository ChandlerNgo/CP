#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

bool dfs(vector<string>& board, string& s, int i, int j, int index, vector<vector<bool>>& visited){
    if(s.size() == index){
        return true;
    }

    if(i < 0 || i >= 4 || j < 0 || j >= 4 || visited[i][j] || board[i][j] != s[index]){
        return false;
    }
    
    for(int di = -1; di <= 1; di++){
        for(int dj = -1; dj <= 1; dj++){
            
            visited[i][j] = true;

            bool found = dfs(board, s, i+di, j+dj, index+1, visited);
            
            visited[i][j] = false;
            
            if(found){
                return true;
            }
        }
    }
    return false;
}

bool searchBoard(vector<string>& board, string s){
    vector<vector<bool>> visited(4, vector<bool>(4, false));
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(dfs(board, s, i, j, 0, visited)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> words(n);
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        words[i] = s;
    }

    vector<int> points = {0,0,0,1,1,2,3,5,11};

    int m;
    cin >> m;
    while(m--){
        vector<string> board;
        for(int i = 0; i < 4; i++){
            string s;
            cin >> s;
            board.push_back(s);
        }

        string maxWord = "";
        int maxPoint = 0;
        int total = 0;
        int num = 0;

        for(auto s : words){
            if(searchBoard(board, s)){
                num += 1;
                total += points[s.size()];
                if(points[s.size()] > maxPoint){
                    maxWord = s;
                    maxPoint = points[s.size()];
                }else if(points[s.size()] == maxPoint && s < maxWord){
                    maxWord = s;
                }
            }
        }

        cout << total << " " << maxWord << " " << num << endl;
    }
}