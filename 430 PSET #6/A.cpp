#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

map<string,pair<ll,string>> letters;
vector<string> letterColumns;

pair<ll,string> dp(string s){
    if(s.size() == 1){
        return {0,s};
    }
    if(letters.find(s) == letters.end()){
        pair<ll,string> minPair = {LLONG_MAX,""};
        for(int i = 1; i < s.size(); i++){
            string left = s.substr(0,i);
            string right = s.substr(i);
            pair<ll,string> leftPair = dp(left);
            pair<ll,string> rightPair = dp(right);

            pair<ll,string> remainingString;
            string combined = leftPair.second+rightPair.second;
            if(letters.find(combined) == letters.end()){
                remainingString = dp(combined);
            }else{
                remainingString = letters[combined];
            }

            remainingString.first += leftPair.first + rightPair.first;

            if(remainingString.first < minPair.first){
                minPair = remainingString;
            }else if(remainingString.first == minPair.first){
                auto leftIt = std::find(letterColumns.begin(), letterColumns.end(), remainingString.second);
                auto rightIt = std::find(letterColumns.begin(), letterColumns.end(), minPair.second);

                if(leftIt < rightIt){
                    minPair = remainingString;
                }
            }
        }
        letters[s] = minPair;
    }
    return letters[s];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll k;
    cin >> k;

    for(ll i = 0; i < k; i++){
        string letter;
        cin >> letter;
        letterColumns.push_back(letter);
    }

    for(ll i = 0; i < k; i++){
        for(ll j = 0; j < k; j++){
            ll amount;
            char dash;
            string letter;
            cin >> amount >> dash >> letter;
            string sequence = letterColumns[i]+letterColumns[j];
            letters[sequence] = {amount,letter};
        }
    }

    ll n;
    cin >> n;

    for(ll i = 0; i < n; i++){
        string s;
        cin >> s;
        pair<ll,string> answer = dp(s);
        cout << answer.first << "-" << answer.second << endl;
    }
    int last;
    cin >> last;
}