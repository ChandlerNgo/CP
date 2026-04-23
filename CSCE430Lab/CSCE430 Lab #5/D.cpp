#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<string,char> morse =
    {
        {".-",'A'},
        {"-...",'B'},
        {"-.-.",'C'},
        {"-..",'D'},
        {".",'E'},
        {"..-.",'F'},
        {"--.",'G'},
        {"....",'H'},
        {"..",'I'},
        {".---",'J'},
        {"-.-",'K'},
        {".-..",'L'},
        {"--",'M'},
        {"-.",'N'},
        {"---",'O'},
        {".--.",'P'},
        {"--.-",'Q'},
        {".-.",'R'},
        {"...",'S'},
        {"-",'T'},
        {"..-",'U'},
        {"...-",'V'},
        {".--",'W'},
        {"-..-",'X'},
        {"-.--",'Y'},
        {"--..",'Z'},
        {"---.",'.'},
        {"..--",'_'},
        {".-.-",','},
        {"----",'?'},
    };
    map<char,string> letters =
    {
        {'A',".-"},
        {'B',"-..."},
        {'C',"-.-."},
        {'D',"-.."},
        {'E',"."},
        {'F',"..-."},
        {'G',"--."},
        {'H',"...."},
        {'I',".."},
        {'J',".---"},
        {'K',"-.-"},
        {'L',".-.."},
        {'M',"--"},
        {'N',"-."},
        {'O',"---"},
        {'P',".--."},
        {'Q',"--.-"},
        {'R',".-."},
        {'S',"..."},
        {'T',"-"},
        {'U',"..-"},
        {'V',"...-"},
        {'W',".--"},
        {'X',"-..-"},
        {'Y',"-.--"},
        {'Z',"--.."},
        {'.',"---."},
        {'_',"..--"},
        {',',".-.-"},
        {'?',"----"},
    };


    string s;
    while(cin >> s){
        string answer = "";
        string morseCode = "";
        string numbers = "";
        for(int i = 0; i < s.size(); i++){
            numbers += to_string(letters[s[i]].size());
            morseCode += letters[s[i]];
        }

        int base = 0;
        for(int i = numbers.size()-1; i >= 0; i--){
            string code = "";
            // cout << morseCode << endl;
            for(int j = base; j < base+(numbers[i]-'0'); j++){
                // cout << j << endl;
                code += morseCode[j];
            }
            answer += morse[code];
            base += (numbers[i]-'0');
        }
        cout << answer << endl;
    }

}