#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int mostFreqSubSeq(string s, int len){
    unordered_map<string,int> sub;

    for(int i = 0; i < s.size()-len+1; i++){
        string cur = s.substr(i,len);
        sub[cur] += 1;
    }

    int maxInt = 0;
    for(auto key : sub){
        maxInt = max(maxInt, key.second);
    }

    return maxInt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    while(getline(cin, s)){
        string newString = "";
        for(auto c : s){
            if(c != ' '){
                newString += c;
            }
        }
        
        
        int answer = INT_MAX;
        int i = 1;
        while(answer > 1){
            answer = mostFreqSubSeq(newString, i);
            if(answer > 1){
                cout << answer << endl;
            }else{
                break;
            }
            i += 1;
        }
        cout << endl;
    }
}