#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int MAXN = 1000001;
    vector<bool> is_h_number(MAXN+1, false);
    vector<bool> is_h_semi_prime(MAXN+1, false);
    vector<int> h_primes;
    vector<int> h_numbers;
    vector<bool> is_h_prime(MAXN+1, true);
    
    // cout << 1 << endl;
    for(int i = 0; i <= MAXN; i++){
        if(i % 4 == 1){
            is_h_number[i] = true;
            h_numbers.push_back(i);
        }else{
            is_h_prime[i] = false;
        }
    }
    
    // cout << 2 << endl;

    is_h_prime[1] = false;
    for(int i = 0; i < MAXN+1; i++){
        if(is_h_number[i] && is_h_prime[i]){
            h_primes.push_back(i);
            for(int j = i*2; j < MAXN+1; j += i){
                is_h_prime[j] = false;
            }
        }else{
            is_h_prime[i] = false;
        }
    }
    
    // cout << 3 << endl;
    
    for(int i = 0; i < h_primes.size(); i++){
        for(int j = i; j < h_primes.size(); j++){
            ll product = (ll)h_primes[i]*h_primes[j];
            if(product > MAXN){
                break;
            }
            is_h_semi_prime[product] = true;
        }
    }

    // cout << 4 << endl;
    
    vector<int> semi_prime_count(MAXN + 1, 0);
    int current = 0;
    for(int i = 1; i <= MAXN; i++){
        if(is_h_semi_prime[i]){
            current += 1;
        }
        semi_prime_count[i] = current;
    }
    // cout << 5 << endl;

    while(cin >> n && n != 0){
        cout << n << " " << semi_prime_count[n] << endl;
    }
}