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
    int steps;
    if((n-r) % 2 == 1){
        steps = ((n-r)/2)+1;
    }else{
        steps = (n-r)/2;
    }

    if(k < steps){
        k = steps;
    }

    k += (2*r)+k;
    cout << k << endl;
}