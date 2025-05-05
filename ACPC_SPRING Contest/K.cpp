#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a;
    int b;
    cin >> a >> b;
    if(b > a){
        swap(a,b);
    }

    if((a+b)% 3 == 0 && (2*b) >= a){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}