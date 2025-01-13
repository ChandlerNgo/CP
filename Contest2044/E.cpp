#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll k; ll l1; ll r1; ll l2; ll r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;
        ll curK = 1;
        ll total = 0;
        while(curK <= (r2/l1)+1){
            total += min(r1-l1+1, ((r2-(curK/l1))/curK)+1);
            curK = curK * k;
        }
        cout << total << endl;
    }
}