#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    char letter;
    string answer;
    map<char,int> letters;
    map<char,bool> solved;
    int score = 0;
    int amtSolved = 0;
    cin >> n;
    while(n != -1){
        cin >> letter >> answer;
        if(letters.find(letter) == letters.end()){
            if(answer == "wrong"){
                letters[letter] += 20;
                solved[letter] = false;
            }else{
                letters[letter] += n;
                solved[letter] = true;
                score += letters[letter];
                amtSolved += 1;
            }
        }else{
            if(answer == "wrong"){
                letters[letter] += 20;
                solved[letter] = false;
            }else{
                letters[letter] += n;
                solved[letter] = true;
                score += letters[letter];
                amtSolved += 1;
            }
        }
        cin >> n;
    }
    cout << amtSolved << " " << score << endl;
}