#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        map<char,int> letters;
        for(int i = 0; i < n; i++){
            if(letters.find(s[i]) == letters.end()){
                letters[s[i]] = 1;
            }else{
                letters[s[i]] += 1;
            }
        }
        int maxLetterFreq = -1;
        char maxLetter = '0';
        char minLetter = '0';
        int minLetterFreq = 20;
        for(auto i = letters.begin(); i != letters.end(); i++){
            if(i->second > maxLetterFreq){
                maxLetterFreq = i->second;
                maxLetter = i->first;
            }
            if(i->second <= minLetterFreq){
                minLetterFreq = i->second;
                minLetter = i->first;
            }
        }
        for(int i = 0; i < n; i++){
            if(s[i] == minLetter){
                s[i] = maxLetter;
                break;
            }

        }
        cout << s << endl;
    }
}