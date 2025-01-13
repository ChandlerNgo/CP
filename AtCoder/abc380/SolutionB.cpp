#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;

    stack<int> dashes;

    for(int i = 1; i < (int)s.size(); i++){
        if(s[i] == '|'){
            cout << dashes.size() << " ";
            while(!dashes.empty()){
                dashes.pop();
            }
        }else{
            dashes.push(1);
        }
    }
    cout << endl;
}