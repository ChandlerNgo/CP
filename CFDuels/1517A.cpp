#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    for(int i = 0; i < t; i++){
        ll n;
        cin >> n;
        if(n < 2050){
            cout << -1 << endl;
        }else{
            ll currentVal = 2050;
            ll currentAmount = 0;
            while(n > 0){
                if(n < 2050 && n != 0){
                    break;
                }
                while(currentVal < n){
                    currentVal *= 10;
                }
                
                if(n == currentVal){
                    n -= currentVal;
                }else{
                    n -= (currentVal/10);
                }
                currentVal = 2050;
                currentAmount += 1;
            }

            if(n == 0){
                cout << currentAmount << endl;
            }else{
                cout << -1 << endl;
            }
        }
    }
}