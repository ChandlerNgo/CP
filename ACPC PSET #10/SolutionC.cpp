#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string s = "";
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        s += temp;
    }
    int groups = 0;
    for(int i = 0; i < s.size()-1; i++){
        if(s[i] == s[i+1]){
            groups += 1;
        }
    }
    cout << groups+1 << endl;
}