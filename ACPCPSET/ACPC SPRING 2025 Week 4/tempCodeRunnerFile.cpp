#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    int a;
    int b;
    cin >> k >> a >> b;
    bool occured = false;
    for(int i = a; i <= b; i++){
        if(i % k == 0){
            occured = true;
            break;
        }
    }
    if(occured){
        cout << "OK" << endl;
    }else{
        cout << "NG" << endl;
    }
}