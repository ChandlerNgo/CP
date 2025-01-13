#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0 ; i < t; i++){
        string word;
        cin >> word;
        string sub = "";
        sub += word[0];
        for(int j = 1; j < word.size(); j += 2){
            sub += word[j];
        }
        cout << sub << endl;
    }
}