#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        ll n; ll k;
        cin >> n >> k;
        int operations = 0;
        while(n != 0){
            ll power = 1;
            while(n >= power*k && k != 1){
                power *= k;
            }
            if(power == 1){
                operations += n;
                break;
            }
            operations += 1;
            n -= power;
        }
        cout << operations << endl;
    }
}