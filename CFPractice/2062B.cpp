#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }

        // each number has to be greater than the distance to leave and return
        // left: 2*num, right : 2(n-num)
        bool possible = true;
        for(int i = 0; i < n; i++){
            if(!(2*i < nums[i] && 2*(n-i-1) < nums[i])){
                possible = false;
                break;
            }
        }

        cout << (possible ? "YES\n" : "NO\n");
    }
}