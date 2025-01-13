#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        string s;
        cin >> s;

        map<int,int> letters;
        for(int j = 0; j < n; j++){
            if(letters.find(s[j] - 'A' + 1) == letters.end()){
                letters[(s[j] - 'A' + 1)] = 1;
            }else{
                letters[(s[j] - 'A' + 1)] += 1;
            }
        }
        int problems = 0;
        for(auto j = letters.begin(); j != letters.end(); j++){
            if(j->first <= j->second){
                problems += 1;
            }
        }
        cout << problems << endl;
    }
}