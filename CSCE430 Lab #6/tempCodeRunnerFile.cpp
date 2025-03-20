#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set<ll> numbers;
    ll n;
    cin >> n;
    for(ll i = 1; i <= (n/2)+1; i++){
        numbers.insert(n-(i*i));
        if(numbers.find(n-(i*i)) != numbers.end()){
            cout << floor(sqrt(n-(i*i))) << " " << i << endl;
            return 0;
        }
    }
    cout << "impossible" << endl;
}