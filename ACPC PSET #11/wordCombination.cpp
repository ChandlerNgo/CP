#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string word;
    cin >> word;
    int length_of_string = word.size();
    int n;
    cin >> n;
    vector<string> dictionary(n);
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        dictionary[i] = str;
    }

    vector<ll> dp(length_of_string+1);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(string dictionary_word : dictionary){
            if(i >= length_of_string){
                string comp = word.substr( i- length_of_string, length_of_string);
                if(dictionary_word == comp){
                    dp[i] = (dp[i] + dp[i-length_of_string]) % 1000000007;
                }
            }
        }
    }
}