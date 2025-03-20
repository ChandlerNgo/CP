#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const int MOD = 1e9 + 7;

vector<vector<ll>> matrix_multiplication(vector<vector<ll>>& a, vector<vector<ll>>& b){
    ll n = a.size();
    vector<vector<ll>> result(n,vector<ll>(n,0));
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            for(ll k = 0; k < n; k++){
                result[i][j] = (result[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
            }
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll k;
    ll n;
    cin >> k >> n;

    vector<vector<ll>> basicMatrix(k,vector<ll>(k,0));
    for(ll i = 1; i <= k; i++){
        for(ll j = 1; j <= k; j++){
            if(gcd(i,j) == 1 && (i != j || i == 1)){
                basicMatrix[i-1][j-1] = 1;
            }
        }
    }
    
    vector<vector<vector<ll>>> matrixForPowerOf2(61,vector<vector<ll>>(k,vector<ll>(k,0)));
    matrixForPowerOf2[0] = basicMatrix;
    for(ll i = 1; i <= 60; i++){ // 2^60 ~ 10^18
        matrixForPowerOf2[i] = matrix_multiplication(matrixForPowerOf2[i-1],matrixForPowerOf2[i-1]);
    }
    
    
    vector<vector<ll>> answer(k,vector<ll>(k,0));
    for(ll i = 0; i < k; i++){
        answer[i][i] = 1;
    }
    n -= 1;
    for(ll i = 0; i <= 60; i++){
        if((n >> i) & 1){
            answer = matrix_multiplication(matrixForPowerOf2[i],answer);
        }
    }
    ll sumAnswer = 0;

    for(ll i = 0; i < answer.size(); i++){
        for(ll j = 0; j < answer.size(); j++){
            sumAnswer = (sumAnswer + answer[i][j]) % MOD;
        }
    }
    cout << sumAnswer << endl;
}