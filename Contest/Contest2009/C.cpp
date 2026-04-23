#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll x;
        ll y;
        ll k;
        cin >> x >> y >> k;
        ll a = (x+k-1)/k;
        ll b = (y+k-1)/k;
        if(a > b){
            cout << a*2-1 << endl;
        }else{
            cout << b*2 << endl;
        }
    }   
}