#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll n,m,k;
        cin >> n >> m >> k;
        ll erase = (n*m - k) / n;
        ll leftover = m-erase;

        if(leftover < erase){
            cout << 1 << endl;
            continue;
        }
        ll answer = (leftover + erase) / (erase+1); // ceil of leftover/(erase+1), max of 'leftover' values split into 'erase+1' chunks
        cout << answer << endl;
    }
}