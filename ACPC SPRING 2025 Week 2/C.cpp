#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    if(n == 2){
        cout << "Yes" << endl;
        return 0;
    }

    vector<ll> numbers;

    for(int i = 0; i < n; i++){
        ll num;
        cin >> num;
        numbers.push_back(num);
    }

    ll factor = gcd(numbers[1],numbers[0]);

    for(int i = 0; i < n-1; i++){
        if(factor != gcd(numbers[i],numbers[i+1])){
            cout << "No" << endl;
            return 0;
        }
    }
    
    cout << "Yes" << endl;
}