#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        ll b; ll c; ll d;
        cin >> b >> c >> d;
        bool found = false;
        for(ll a = 0; a <= max(max(b,c),d); a++){
            if(((a | b) - (a & c)) == d){
                cout << a << endl;
                found = true;
                break;
            }
        }
        if(!found){
            cout << -1 << endl;
        }
    }
}