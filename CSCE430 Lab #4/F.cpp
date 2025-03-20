#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++){
        ll num; ll p; char c; ll q;
        cin >> num >> p >> c >> q;
        if(q == 1){
            cout << num << " " << q << c << p+1 << endl;
        }else{
            ll times = p/q;
            // to the left
            ll newP = p-(q*times);
            ll newQ = q;
            
            // to the right
            newQ = newQ-newP;

            // down right
            newP = newP+newQ;

            // down left
            newQ = newQ + newP*times;

            cout << num << " " << newP << c << newQ << endl;
        }
    }   
}