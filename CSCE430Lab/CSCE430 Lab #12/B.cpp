#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    map<string,int> appearances;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        string newString = "";
        if(appearances.find(s) == appearances.end()){
            cout << 0 << endl;
        }else{
            cout << appearances[s] << endl;
        }
        for(int j = 0; j < s.size(); j++){
            newString += s[j];
            appearances[newString] += 1;
        }
    }
}