#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> squares;
    vector<ll> numbers;
    vector<ll> prefixSquares;
    vector<ll> prefixNumbers;
    ll curSquareSum = 0;
    ll curNumberSum = 0;
    for(ll i = 0; i < n; i++){
        ll num;
        cin >> num;
        curSquareSum += (num*num);
        curNumberSum += (num);
        numbers.push_back(num);
        squares.push_back(num*num);
        prefixSquares.push_back(curSquareSum);
        prefixNumbers.push_back(curNumberSum);
    }

    ll maxVal = -1;
    for(ll k = 0; k < n; k++){
        maxVal = max(maxVal,prefixSquares[k] * (curNumberSum - prefixNumbers[k]));
    }
    cout << maxVal << endl;
}