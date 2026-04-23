#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

vector<ll> sequence;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    ll k;
    cin >> n >> k;

    sequence.push_back(0);
    sequence.push_back(1);
    sequence.push_back(1);
    for(ll i = 0; i <= n; i++){
        sequence.push_back(sequence[sequence.size()-2]+sequence[sequence.size()-1]);
    }

    while(n > 2){
        if(k > sequence[n-2]){
            k -= sequence[n-2];
            n -= 1;
        }else{
            n -= 2;
        }
    }



    cout << ((n == 1) ? "N" : "A") << endl;

}