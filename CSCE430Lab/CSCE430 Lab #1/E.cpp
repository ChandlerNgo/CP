#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<char,int> cards;
    for(int i = 0; i < 5; i++){
        string s;
        cin >> s;
        if(cards.find(s[0]) == cards.end()){
            cards[s[0]] = 1;
        }else{
            cards[s[0]] += 1;
        }
    }
    int maxAnswer = 1;
    for(auto i = cards.begin(); i != cards.end(); i++){
        if(i->second > maxAnswer){
            maxAnswer = i->second;
        }
    }
    cout << maxAnswer << endl;
}