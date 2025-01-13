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
        int number = 0;
        bool isNeg = true;
        int j = 1;
        while(number >= (-1*n) && number <= n){
            if(isNeg){
                number -= ((j*2)-1);
            }else{
                number += ((j*2)-1);
            }
            isNeg = !isNeg;
            j += 1;
        }
        if(number < 0){
            cout << "Sakurako" << endl;
        }else{
            cout << "Kosuke" << endl;
        }
    }
}