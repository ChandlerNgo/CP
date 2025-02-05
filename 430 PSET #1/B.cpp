#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int j = 1; j <= t; j++){
        string alien;
        string source;
        string target;
        cin >> alien >> source >> target;
        map<char,ll> sourceToDigit;
        for(ll i = 0; i < source.length(); i++){
            sourceToDigit[source[i]] = i;
        }
        ll number = 0;
        for(ll i = alien.length()-1; i >= 0; i--){
            number += sourceToDigit[alien[i]]*pow(source.length(),(alien.length()-1)-i);
        }

        // convert decimal to whatever base
        stack<ll> numbers;
        ll remainder;
        while(number != 0){
            numbers.push(number % target.length());
            number /= target.length();
        }
        cout << "Case #" << j << ": ";
        while(!numbers.empty()){
            cout << target[numbers.top()];
            numbers.pop();
        }
        cout << endl;
    }
}
