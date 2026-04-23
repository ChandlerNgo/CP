#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

void makeSquare(int n, vector<string>& board, map<int,pair<int,int>> pairing){
    if(n % 2 == 0){
        string row = "";
        while(pairing[n].first--){
            row += "<=>";
        }
        while(pairing[n].second--){
            row += "<==>";
        }
        cout << row.size() << endl;
        for(int i = 0; i < board.size(); i++){

            for(int j = 0; j < row.size(); j++){
                board[i][j] = row[j];
            }
            cout << board[i].size() << endl;
        }
    }else{
        for(int k = 0; k < (n-3)/2; k++){

            pair<int,int> pairingCopy = pairing[n-(2*k)-1];
            string row = "";
            string column = "";
            while(pairingCopy.first--){
                row += "<=>";
                column += "^#V";
            }
            while(pairingCopy.second--){
                row += "<==>";
                column += "^##V";
            }

            for(int i = k; i <= n-k-2; i++){
                int j = k;
                board[j][i] = row[i-k];
            } // topleft

            for(int i = k+1; i <= n-k-1; i++){
                int j = n-k-1;
                board[j][i] = row[i-k+1];
            }
            
            for(int j = k+1; j <= n-k-1; j++){
                int i = k;
                board[j][i] = column[j-k+1];
            }

            for(int j = k; j <= n-k-2; j++){
                int i = n-k-1;
                board[j][i] = column[j-k];
            }
        }

        for(int i = (n-3)/2; i < ((n-3)/2) + 3; i++){
            string row = "<=>";
            for(int j = 0; j < 3; j++){
                board[i][j+(n-3)/2] = row[j];
            }
        }

    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    if(n <= 2){
        cout << "Impossible" << endl;
    }
    
    map<int,pair<int,int>> pairing;
    for(int i = 0; i <= 1000; i++){
        for(int j = 0; j <= 1000; j++){
            int number = i*3 + j*4;
            if(number >= 1 && number <= 1000){
                pairing[number] = {i,j};
            }
        }
    }

    for(auto x : pairing){

    }

    vector<string> board(n,string('!',n));

    makeSquare(n,board, pairing);

    for(int i = 0; i < n; i++){
        cout << board[i].size() << endl;
        cout << board[i] << endl;
    }
}

^<==>
#<=>^
#<=>#
V<=>#
<==>V