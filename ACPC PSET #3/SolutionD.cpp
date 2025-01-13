#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;

    vector<ll> numbers;

    for(int i = 0; i < n; i++){
        ll num;
        cin >> num;
        numbers.push_back(num);
    }

    sort(numbers.begin(),numbers.end(),greater<ll>());

    ll currentAnswer = 0;
    ll currentSum = numbers[0];
    for(int i = 1; i < numbers.size(); i++){
        currentAnswer += (currentSum - i*numbers[i]);
        currentSum += numbers[i];
    }

    // 5 2 1
    // 

    cout << currentAnswer << endl;
}