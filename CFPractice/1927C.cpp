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
        int n,m,k;
        cin >> n >> m >> k;
        vector<int> a(k+1);
        vector<int> b(k+1);
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            if(num <= k){
                a[num] = 1;
            }
        }
        for(int i = 0; i < m; i++){
            int num;
            cin >> num;
            if(num <= k){
                b[num] = 1;
            }
        }

        int need = k/2;
        int aCount = 0;
        int bCount = 0;
        int bothCount = 0;
        for(int i = 1; i <= k; i++){
            if(a[i] && b[i]){
                bothCount += 1;
            }else if(a[i]){
                aCount += 1;
            }else if(b[i]){
                bCount += 1;
            }
        }

        if(aCount < bCount){
            int amount = min(bCount-aCount, bothCount);
            aCount += amount;
            bothCount -= amount;
        }else if(aCount > bCount){
            int amount = min(aCount-bCount, bothCount);
            bCount += amount;
            bothCount -= amount;
        }

        if(bothCount > 1){
            aCount += bothCount/2;
            bCount += bothCount/2;
        }

        if(aCount >= need && bCount >= need){
            cout << "YES" << "\n";
        }else{
            cout << "NO" << "\n";
        }
    }
}