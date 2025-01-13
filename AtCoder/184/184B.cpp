#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    // keep all elements contribution
    // grab the highest element
    vector<int> amounts(n+1,INT_MAX);
    amounts[0] = 0;
    amounts[1] = 1;
    for(int i = 1; i <= n; i++){
        if(amounts[i] == INT_MAX){
            continue;
        }
        if(i+1 <= n){
            amounts[i+1] = min(amounts[i+1], amounts[i]+1);
        }
        if(i*2 <= n){
            amounts[i*2] = min(amounts[i*2], amounts[i]+1);
        }
        if(i*3 <= n){
            amounts[i*3] = min(amounts[i*3], amounts[i]+1);
        }
    }
    cout << amounts[n] << endl;
}