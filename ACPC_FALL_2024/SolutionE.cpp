#include <bits/stdc++.h>

using namespace std;

int main(){
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int n;
    int m;
    int k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        string curString;
        cin >> curString;
        for(int j = 0; j < m; j++){
            if(curString[j] == 't'){
                curString[j] = alphabet[(j+i) % k];
            }
        }
        cout << curString << endl;
    }

}