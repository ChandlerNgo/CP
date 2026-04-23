#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int sumByIndex(int n, int k, int i){
    int leftSide = (i-1)*(k + k + i - 1)/2; // k to k+i-1
    int rightSide = (n-i-1)*(k + i + k + n - 1)/2; // k+i to k+n-1
    return abs(leftSide-rightSide);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; // length
        int k; // starting element
        cin >> n >> k;
        int localMin = INT_MAX;
        int localIndex = -1;
        for(int i = k; i < k+n+1; i++){
            localMin = min(localMin,sumByIndex(n,k,i));
            if(sumByIndex(n,k,i) > localMin){
                localIndex = i;
                localMin = sumByIndex(n,k,i);
            }
        }
        cout << localIndex << endl;
    }
}