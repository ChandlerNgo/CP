#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        string first;
        string second;
        cin >> first >> second;
        int reversed = 0;
        int forward = 0;
        for(int j = 0; j < n; j++){
            if(first[j] == second[j]){
                forward += 1;
            }
            if(first[j] == second[n-j-1]){
                reversed += 1;
            }
        }

        if(forward == n){
            cout << 0 << endl;
        }else if(reversed == n){
            cout << 2 << endl;
        }else if(forward > reversed){
            int needsReversing = (n-forward) % 2 == 1;
            cout << ((n-forward)*2) - needsReversing << endl;
        }else if(forward < reversed){
            int needsReversing = (n-reversed) % 2 == 0;
            cout << ((n-reversed)*2) - needsReversing << endl;
        }else if(forward == reversed){
            cout << (2 * (n-forward)) - 1 << endl;
        }
    }
}