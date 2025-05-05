#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    char current = s[0];

    int up = 0;
    int down = 0;
    int leave = 0;
    for(int i = 1; i < s.size(); i++){
        if(current != s[i]){
            up += 1;
            current = s[i];
        }
        if(current != 'U'){
            current = 'U';
            up += 1;
        }
    }
    current = s[0];
    for(int i = 1; i < s.size(); i++){
        if(current != s[i]){
            down += 1;
            current = s[i];
        }
        if(current != 'D'){
            current = 'D';
            down += 1;
        }
    }

    current = s[0];
    for(int i = 1; i < s.size(); i++){
        if(current != s[i]){
            leave += 1;
            current = s[i];
        }
    }

    cout << up << endl;
    cout << down << endl;
    cout << leave << endl;
}