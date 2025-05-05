#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while(n != 0){
        vector<string> words;
        while(n--){
            string s;
            cin >> s;
            words.push_back(s);
        }

        string maxWord = "";
        int pairs = 0;

        set<char> vowels = {'a','e','i','o','u','y'};
        for(int i = 0; i < words.size(); i++){
            int curPairs = 0;
            for(int j = 0; j < words[i].size()-1; j++){
                if(vowels.find(words[i][j]) != vowels.end() && words[i][j] == words[i][j+1]){
                    curPairs += 1;
                }
            }

            if(curPairs > pairs){
                pairs = curPairs;
                maxWord = words[i];
            }
        }
        cout << maxWord << "\n";

        cin >> n;
    }
    cout << endl;
}