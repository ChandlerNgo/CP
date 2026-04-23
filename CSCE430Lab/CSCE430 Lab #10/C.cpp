#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string command;
    cin >> command;

    ll shares = 0;
    ld shareMoney = 0;

    while(command != "die"){
        if(command == "buy" || command == "sell"){
            ll x;
            ll y;
            cin >> x >> y;
            if(command == "buy"){
                shares += x;
                shareMoney += (x*y);
            }

            if(command == "sell"){
                ld currentSharePrice = shareMoney / shares;
                shares -= x;
                shareMoney -= (currentSharePrice*x);
            }
        }else{
            ll x;
            cin >> x;
            if(command == "split"){
                shares *= x;
            }
            
            if(command == "merge"){
                ll remainingShares = shares % x;
                ld currentSharePrice = shareMoney / shares;
                shares -= remainingShares;
                shareMoney -= (currentSharePrice*remainingShares);
                shares /= x;
            }
        }
        cin >> command;
    }

    ll y;
    cin >> y;
    
    // dead
    ld currentSharePrice = shareMoney / shares;
    ld soldAmount = y*shares;
    if(soldAmount < shareMoney){
        cout << soldAmount << endl;
    }else{
        cout << fixed << setprecision(1) << (soldAmount - ((soldAmount - shareMoney) * 0.3)) << endl;
    }
}