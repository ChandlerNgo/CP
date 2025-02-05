#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    set<char> letters;
    map<char,char> letterConversion;
    letterConversion['R'] = 'S';
    letterConversion['B'] = 'K';
    letterConversion['L'] = 'H';
    string answer = "";
    queue<char> currentLetters;
    for(int i = 0; i < s.length(); i++){
        if(letters.find(s[i]) == letters.end()){
            currentLetters.push(s[i]);
            letters.insert(s[i]);
        }else{
            if(letters.size() == 3){
                answer += 'C';
                while(!currentLetters.empty()){
                    currentLetters.pop();
                }
                letters.clear();
            }else{
                char letter;
                while(letters.find(s[i]) != letters.end()){
                    letter = currentLetters.front();
                    currentLetters.pop();
                    letters.erase(letter);
                    answer += letterConversion[letter];
                }
                letters.insert(letter);
                currentLetters.push(letter);
            }
        }
        if(letters.size() == 3){
            answer += 'C';
            while(!currentLetters.empty()){
                currentLetters.pop();
            }
            letters.clear();
        }
    }
    while(!currentLetters.empty()){
        answer += letterConversion[currentLetters.front()];
        currentLetters.pop();
    }
    cout << answer << endl;
}