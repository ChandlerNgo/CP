#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int r;
    int k;
    cin >> n >> r >> k;
    int steps = k+abs(r-k);

    if(steps < n){
        if((n-steps) % 2 == 1){
            steps += (n-steps+1);
        }else{
            steps += (n-steps);
        }
    }

    steps += r;

    cout << steps << endl;
}