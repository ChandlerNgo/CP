#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] == 'q'){
                cout << 'p';
            }else if(s[i] == 'p'){
                cout << 'q';
            }else{
                cout << 'w';
            }
        }
        cout << endl;
    }
}