#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        if(n == 2){
            cout << "YES" << endl;
            continue;
        }

        if(n % 2 == 0){
            int sqrtN = sqrt(n);
            int sqrtN2 = sqrt(n/2);
            if(sqrtN * sqrtN == n/2 || sqrtN * sqrtN == n){
                cout << "YES" << endl;
                continue;
            }
            if(sqrtN2 * sqrtN2 == n/2 || sqrtN2 * sqrtN2 == n){
                cout << "YES" << endl;
                continue;
            }
        }
        cout << "NO" << endl;
    }
}